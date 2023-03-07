sh prepare.sh
/home/user/symbolic_array/case_studies/tools/klee/Release+Asserts/bin/klee --optimize-array=all --array-value-ratio=.75 --stop-after-n-instructions=57430294 --stats-write-interval=1500 --istats-write-interval=1500 --simplify-sym-indices --output-module --max-memory=4095 --allocate-determ=true --allocate-determ-size=4095 --allocate-determ-start-address=0x7ffef66f3000 --max-sym-array-size=4096 --disable-inlining --optimize --use-forked-solver --use-cex-cache --libc=uclibc --posix-runtime --allow-external-sym-calls --only-output-states-covering-new --watchdog --max-memory-inhibit=false --use-query-log=solver:kquery --max-static-fork-pct=1 --max-static-solve-pct=1 --max-static-cpfork-pct=1 --switch-type=internal --dump-states-on-halt=false --debug-print-instructions=compact:file --debug-compress-instructions --compress-query-log --environ=/tmp/test.env --run-in=/tmp/sandbox --max-instruction-time=200. --max-solver-time=200. --max-time=1800 --search=dfs --output-dir=klee-out-factor-opt /home/user/symbolic_array/case_studies/coreutils/coreutils-6.11/obj-llvm/src/factor.bc --sym-args 0 1 10 --sym-args 0 2 2 --sym-files 1 8 --sym-stdin 8 --sym-stdout
