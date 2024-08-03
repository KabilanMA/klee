#!/bin/bash 
source ./run-bench-common.sh

if [ -z "$1" ]; then
    echo "Please provide a run script number (1-4) as an argument."
    exit 1
fi

case $1 in
    1)
        COMMAND="run_bench \"toupper\" \"10 50 100\" \"5\" \"klee_cfm_verify\""
        ;;
    2)
        COMMAND="run_bench \"toupper\" \"10 50 100\" \"5\" \"klee_sm_verify\""
        ;;
    3)
        COMMAND="run_bench \"toupper\" \"10 50 100\" \"5\" \"klee_cfmsm_verify\""
        ;;
    4)
        COMMAND="run_bench \"toupper\" \"10 50 100\" \"1\" \"klee_verify\""
        ;;
    *)
        echo "Invalid option. Please provide a number between 1 and 4."
        exit 1
        ;;
esac

echo "The following command will be executed:"
echo $COMMAND

read -p "Do you want to proceed? (yes/no): " CONFIRMATION

if [ "$CONFIRMATION" = "yes" ]; then
    eval $COMMAND
else
    echo "Operation cancelled."
    exit 0
fi

# run_bench "toupper" "10 50 100" "5" "klee_cfm_verify"
# run_bench "toupper" "10 50 100" "5" "klee_sm_verify"
# run_bench "toupper" "10 50 100" "5" "klee_cfmsm_verify"
# run_bench "toupper" "10 50 100" "1" "klee_verify"

echo "Done" | mail -s "toupper run complete!" $USER
