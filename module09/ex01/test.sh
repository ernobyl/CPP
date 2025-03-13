#!/bin/bash

RPN_PROGRAM="./RPN"

# Function to run a test and check output
run_test() {
    local expr="$1"
    local expected="$2"

    result=$($RPN_PROGRAM "$expr" 2>&1)

        echo "$expr"
        echo "Expected: $expected"
        echo "Got: $result"
        echo ""
}

# Valid cases
run_test "8 9 *" "72"
run_test "3 4 + 2 *" "14"
run_test "2 3 + 5 6 + *" "55"
run_test "8 -9 *" "-72"

# Invalid cases
run_test "3 +" "(error message)"
run_test "5 0 /" "(error message)"
run_test "10 99 /" "(error message)"
run_test "8 9 * 10 +" "(error message)"
run_test "10 *" "(error message)"

# Invalid characters
run_test "8 9 * a +" "(error message)"
run_test "1 x 5 +" "(error message)"
run_test "3 4 + @ 5 +" "(error message)"

# Overflow test
run_test "6 0 /" "(error message)"
run_test "8 9 * 9 9 9 9 * * * * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *" "integer overflow"

# Invalid format test (no space between numbers)
run_test "" "empty argument"
run_test "3 5 * * * * * *" "(error message)"
