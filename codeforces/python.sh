#!/bin/bash

# Check if both the Python file and test case file are provided
if [ $# -ne 2 ]; then
    echo "Usage: ./run_python.sh <source_file.py> <test_case_file>"
    exit 1
fi

source_file=$1
test_case_file=$2

# Check if the Python source file exists
if [ ! -f "$source_file" ]; then
    echo "Error: The Python source file '$source_file' does not exist."
    exit 1
fi

# Check if the test case file exists
if [ ! -f "$test_case_file" ]; then
    echo "Error: The test case file '$test_case_file' does not exist."
    exit 1
fi

# Run the Python script with the input from the test case file
echo "Running the Python script '$source_file' with input from '$test_case_file'..."
python3 "$source_file" < "$test_case_file"