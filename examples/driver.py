import subprocess
import os
import re
import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import multiprocessing

DEBUG = False

test_dirs = ['./false_positive/', './erosion/', './dilation/', './detect_edges/']
test_names = ['false_positive', 'erosion', 'dilation', 'detect_edges']

config = {
  ## CHANGE THESE FOR YOUR SPECIFIC BUILD SYSTEM
  'KLEE_BUILD_DIR': "/home/shay/a/rgangar/PLCL/klee/build",
  'LLVM_BUILD_DIR': "/home/shay/a/rgangar/PLCL/llvm-project-rocm/build_cfmse_install",
  ## SETTINGS BELOW CAN BE LEFT UNCHANGED
  'CLANG': lambda: config['LLVM_BUILD_DIR'] + "/bin/clang",
  'OPT': lambda: config['LLVM_BUILD_DIR'] + "/bin/opt",
  'CFMSE_FLAGS': "--enable-new-pm -mem2reg -S",
  'KLEE_INCLUDE': lambda: config['KLEE_BUILD_DIR'] + "/../include",
  'CLANG_FLAGS': lambda: "-I " + config['KLEE_INCLUDE']() + " -emit-llvm -S -Xclang -disable-O0-optnone",
  'KLEE_NOCFM_OPTIONS': "--max-memory=51200 --max-time=1h --only-output-states-covering-new --write-cov",
  'KLEE_CFM_OPTIONS': lambda: config['KLEE_NOCFM_OPTIONS'] + " --klee-cfmse",
  'KLEE_BIN': lambda: config['KLEE_BUILD_DIR'] + "/bin/klee"
}

def analyzeErroringTest(ktest_path, test_directory, testfile_prefix):
  print("Analyzing Erroring Test:", ktest_path)
  print("Test Directory:", test_directory)
  print("Testfile Prefix:", testfile_prefix)
  if DEBUG:
    subprocess.run(['ktest-tool', ktest_path]) ## outputs failing test inputs
  
  command = config['KLEE_BIN']() + " --replay-ktest-file=" + ktest_path + " " + test_directory + testfile_prefix + ".ll"
  if DEBUG:
    print(command)
  print("\033[1;35m", end = "")
  print("KLEE replaying test ->", ktest_path, end ="")
  print("\033[0m")
  process = subprocess.Popen(command, stderr=subprocess.PIPE, shell=True)
  error_detected = False
  
  while True:
      # Read a line from the subprocess's standard output
    output = process.stderr.readline()
    output_str = output.decode().strip()
    
    if b'KLEE: ERROR' in output:
      print("\033[1;31m",end ="")
      print(output_str, end ="")
      print("\033[0m")
      error_detected = True

    # If there's no more output, break the loop
    if output == b'' and process.poll() is not None:
      break
    
  #return_code = process.poll()
  if(not error_detected):
    print("\033[1;32mErroring Test is a false positive ->", ktest_path , end ="")
    print("\033[0m")
  else:
    print("\033[1;31mErroring Test is a real error ->", ktest_path , end ="")
    print("\033[0m")
  
class TestDirectoryHandler(FileSystemEventHandler):
    def __init__(self):
      super().__init__
      self.main_test_output_directory = ""
    def on_any_event(self, event):
        if event.event_type == 'modified':
            if(".err" in event.src_path): # if an erroring test case has been made
              test_output_directory = os.path.dirname(event.src_path)
              if(self.main_test_output_directory == "" or self.main_test_output_directory == test_output_directory):
                print(f"Erroring Test is: {event.src_path}")
              match = re.search(r"test\d{6}", event.src_path)
              if match:
                test_number = match.group(0)
                test_directory = os.path.dirname(test_output_directory) + "/"
                index_of_test_directory = test_dirs.index(test_directory)
                testname_prefix = test_names[index_of_test_directory]
                
                ## analyze if error is a false positive
                if(self.main_test_output_directory == "" or self.main_test_output_directory == test_output_directory):
                  new_process = multiprocessing.Process(target=analyzeErroringTest, args=(test_output_directory + "/" + test_number + ".ktest", test_directory, testname_prefix))
                  new_process.start() ## run false positive error analysis on different process
                  self.main_test_output_directory = test_output_directory
              else:
                print("No match found")

if __name__ == "__main__":
  
  for index in range(len(test_dirs)):
    print("---------------------------------------------------------------------------")
    test_dir = test_dirs[index]
    testname_prefix = test_names[index]
    c_file = test_dir + testname_prefix + ".c"
    ll_file = test_dir + testname_prefix + ".ll"
    print("\033[1;35m", end ="")
    print("KLEE executing test ->", test_dir, end ="")
    print("\033[0m")
    # Clean test directory
    subprocess.run(['make', 'clean', '-C', test_dir, '--no-print-directory'])
    
    # Make .ll file
    command = config['CLANG']() + " " \
      + config['CLANG_FLAGS']() + " " \
      + c_file \
      + " -o " + ll_file
    if DEBUG:
      print(command)
    subprocess.run(command, shell=True)
    
    # Run opt on .ll file
    command = config['OPT']() + " -f " \
      + config['CFMSE_FLAGS'] + " -o " \
      + ll_file + " < " + ll_file
    if DEBUG:
      print(command)
    subprocess.run(command, shell=True)
    
    #Execute KLEE with transformation on program
    command = config['KLEE_BIN']() + " " + config['KLEE_CFM_OPTIONS']() + " " + ll_file
    if DEBUG:
      print(command)
    
    ## start a process to detect when files get added/changed
    observer = Observer()
    path = test_dir
    event_handler = TestDirectoryHandler()
    observer.schedule(event_handler, path, recursive=True)
    observer.start()
    
    process = subprocess.Popen(command, stderr=subprocess.PIPE, shell=True)
    
    while True:
      # Read a line from the subprocess's standard output
      output = process.stderr.readline()
      output_str = output.decode().strip()
      
      if(DEBUG):
        if b'KLEE: WARNING' in output:
          print("\033[1;35m", end ="")
          print(output_str, end ="")
          print("\033[0m")
      
      if b'KLEE: ERROR' in output:
        print("\033[1;31m",end ="")
        print(output_str, end ="")
        print("\033[0m")
      
      if b'KLEE: done:' in output:
        print("\033[1;32m",end ="")
        print(output_str, end ="")
        print("\033[0m")

      # If there's no more output, break the loop
      if output == b'' and process.poll() is not None:
        break

    # Get the subprocess's return code
    return_code = process.poll()

    # Print the return code
    if(return_code == 0):
      print("\033[1;32mSymbolic execution with transform finished successfully for test ->", test_dir, end ="")
      print("\033[0m")
    else:
      print("\033[1;31mSymbolic execution with transform failed for test ->", test_dir, end ="")
      print("\033[0m")
    observer.stop()
    observer.join()

  
  