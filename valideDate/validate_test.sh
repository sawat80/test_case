#!/bin/bash

# Compile the C program
gcc -o date_check validate.c

# Test cases and expected results
declare -A test_cases=(
    ["29 2 2024"]="Valid date: 29/02/2024"   # Valid date (Leap year)
    ["29 2 2023"]="Invalid day: 29 for month: 2"   # Invalid date (Non-leap year)
    ["31 4 2023"]="Invalid day: 31 for month: 4"   # Invalid date (April has 30 days)
    ["15 6 2023"]="Valid date: 15/06/2023"   # Valid date
    ["32 1 2023"]="Invalid day: 32 for month: 1"   # Invalid date (Day out of range)
    ["12 13 2023"]="Invalid month: 13"  # Invalid date (Month out of range)
    ["10 10 2023"]="Valid date: 10/10/2023"  # Valid date
    ["1 1 2020"]="Valid date: 01/01/2020"    # Valid date (New Year)
    ["30 2 2021"]="Invalid day: 30 for month: 2"   # Invalid date (Feb in non-leap year)
    ["31 12 2021"]="Valid date: 31/12/2021"  # Valid date (New Year's Eve)
)

GREEN='\033[0;32m'
RED='\033[0;31;5m'  # Blinking red
NC='\033[0m'       # No Color
INVERSE='\033[7m'   # Inverse video
# Run each test case
for test in "${!test_cases[@]}"; do
    expected="${test_cases[$test]}"
    echo -e "${INVERSE}Running test case:${NC} $test"
    # Capture the output of the program
    output=$(./date_check $test)

    echo "Output: $output"

    # Compare output with expected
    if [[ "$output" == *"$expected"* ]]; then
        echo -e "${GREEN}Test Passed!${NC}"
    else
        echo -e "${RED}Test Failed! Expected: '$expected', Got: '$output'${NC}"
    fi
    echo "----------------------"
done
