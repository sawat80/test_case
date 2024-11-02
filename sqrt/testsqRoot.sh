#!/bin/bash

# Define color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the C program
gcc -o sqrt_approx squareRoot.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Test cases: pairs of input values and their expected square roots
# Format: "input expected_output"
test_cases=(
    "4 2.0"
    "9 3.0"
    "16 4.0"
    "25 5.0"
    "0 0.0"
    "1 1.0"
    "2 1.41421"
    "10 3.16228"
)

# Tolerance for floating-point comparison
tolerance=0.0001
for test_case in "${test_cases[@]}"; do
    # Split test case into input and expected output
    input=$(echo $test_case | cut -d ' ' -f 1)
    expected_output=$(echo $test_case | cut -d ' ' -f 2)

    # Run the program with the input
    output=$(./sqrt_approx "$input" | awk '{print $NF}')

    # Calculate the absolute difference
    difference=$(echo "$output - $expected_output" | bc -l | awk '{if($1<0) $1=-$1}1')

    # Check if difference is within tolerance
    if (( $(echo "$difference < $tolerance" | bc -l) )); then
        echo -e "${GREEN}Test passed${NC} for input $input: output $output (expected $expected_output)"
    else
        echo -e "${RED}Test failed${NC} for input $input: output $output (expected $expected_output)"
    fi
done

