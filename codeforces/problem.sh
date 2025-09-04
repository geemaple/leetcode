#!/bin/bash

# Check if the problem link is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <problem_link>"
    exit 1
fi

problem_link=$1

# Ask for the problem title
echo "Enter the problem title:"
read problem_title

# Extract the problem number and the corresponding letter from the link (e.g., 2134-B)
problem_number=$(echo "$problem_link" | sed -n 's/.*\/problemset\/problem\/\([0-9]*\)\/\([A-Za-z]\)$/\1\2/p')

# Derive the file name from the title
file_name=$(echo "$problem_title" | sed 's/^[A-Za-z]*\. //' | sed 's/ /-/g' | tr '[:upper:]' '[:lower:]')

# Combine the problem number and the derived title to create the final file name
final_file_name="${problem_number}.${file_name}"

# Create the .py and .cpp files
touch "$final_file_name.py"
touch "$final_file_name.cpp"

# Optional: Print the names of the created files
echo "Created files: $final_file_name.py and $final_file_name.cpp"