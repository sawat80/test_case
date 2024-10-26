#!/bin/bash

# Compile the C program
gcc -o next_day dayafter.c

# Test cases and expected results
declare -A test_cases=(
    ["28 2 2023"]="01/03/2023"    # Non-leap year
    ["29 2 2024"]="01/03/2024"    # Leap year
    ["31 12 2024"]="01/01/2025"    # End of the year
    ["30 4 2023"]="01/05/2023"    # End of April
    ["31 1 2023"]="01/02/2023"    # End of January
    ["31 8 2023"]="01/09/2023"    # End of August
    ["15 10 2023"]="16/10/2023"    # Regular day
    ["30 6 2023"]="01/07/2023"    # End of June
    ["31 3 2023"]="01/04/2023"    # End of March
    ["31 2 2023"]="01/02/2023"   # Invalid date (February 31)
    ["0 1 2023"]="Invalid date"    # Invalid date (0th day)
    ["15 13 2023"]="Invalid date"   # Invalid date (Month 13)
    ["32 1 2023"]="Invalid date"    # Invalid date (32nd day)
)

# Color codes for output
GREEN='\033[0;32m'
RED='\033[0;31;5m'  # Blinking red
NC='\033[0m'       # No Color
INVERSE='\033[7m'   # Inverse video

# Run each test case
for test in "${!test_cases[@]}"; do
    expected="${test_cases[$test]}"
    echo -e "${INVERSE}Running test case:${NC} $test"
    
    # Capture the output of the program
    output=$(./next_day $test 2>&1)  # Capture error messages as well
    
    echo "Output: $output"
    
    # Compare output with expected
    if [[ "$output" == *"$expected"* ]]; then
        echo -e "${GREEN}Test Passed!${NC}"  # Green color for pass
    else
        echo -e "${RED}Test Failed!${NC} Expected: '$expected', Got: '$output'"  # Red color for fail
    fi
    echo "----------------------"
done
