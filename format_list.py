import re
import sys
import os
from collections import defaultdict

def format_markdown_list(sub, folder=""):
    file_path = os.path.join(folder, sub)
    with open(file_path, 'r') as file:
        lines = file.readlines()

    duplicates = set()
    formatted_lines = []
    current_number = 0
    statistic = defaultdict(int)
    
    for line in lines:
        # Match markdown list lines
        match = re.match(r'^\s*(\d+)\.\s+(.*)', line)
        if match:
            problem = match.group(2)
            statistic[problem] += 1
            if problem in duplicates:
                formatted_lines.append('---dup---\n')
            else:
                duplicates.add(problem)
                current_number += 1
                formatted_lines.append(f"{current_number}. {problem}\n")
        else:
            if line.strip() == '':
                duplicates = set()
            formatted_lines.append(line)

    with open(file_path, 'w') as file:
        file.writelines(formatted_lines)

    print(f"{sub}, questions = {current_number}, duplidate= {[k for k, v in statistic.items() if v > 1]}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python format.py <file_path>")
        sys.exit(1)

    file_path = sys.argv[1]
    if os.path.isdir(file_path):
        for sub in os.listdir(file_path):
            format_markdown_list(sub, file_path)
    else:
        format_markdown_list(file_path)