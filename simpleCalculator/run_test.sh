#!/bin/bash

# Compile the C program
gcc -o calculator calculator.c

# Test cases (num1 operator num2 expected_output)
declare -A test_cases=(
    ["2 + 3"]="Result: 5.00"
    ["10 - 4"]="Result: 6.00"
    ["6 * 7"]="Result: 42.00"
    ["8 / 2"]="Result: 4.00"
    ["5 / 0"]="Error: Division by zero!"
    ["5 ^ 2"]="Error: Invalid operator! Use +, -, *, or /."
)
# Color codes for output
GREEN='\033[0;32m'
RED='\033[0;31;5m'  # Blinking red
NC='\033[0m'       # No Color
INVERSE='\033[7m'   # Inverse video
# Run each test case
for test in "${!test_cases[@]}"; do
    IFS=' ' read -r num1 operator num2 <<< "$test"
    expected="${test_cases[$test]}"

    echo -e "${INVERSE}Running test:${NC} $test"
    
    # Capture the output of the program
    output=$(./calculator "$num1" "$operator" "$num2" 2>&1)  # Capture error messages as well
    
    echo "Output: $output"
    
    # Compare output with expected
    if [[ "$output" == *"$expected"* ]]; then
        echo -e "${GREEN}Test Passed!${NC}"  # Green color for pass
    else
        echo -e "${RED}$Test Failed! Expected: '$expected', Got: '$output'${NC}$"  # Red color for fail
    fi
    echo "----------------------"
done
# Clean up
rm calculator
