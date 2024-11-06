import json
import os
import pandas as pd
current_file_path = os.path.abspath(__file__)
current_directory = os.path.dirname(current_file_path)
parent_directory = os.path.dirname(current_directory)
json_file = os.path.join(current_directory, 'reddit_leetcode_google.json')
csv_file = os.path.join(current_directory, 'leetcode-companywise-interview-questions-google.csv')


destination = os.path.join(parent_directory, 'leetcode-google.md')

lines = [
    '# [Google](https://www.reddit.com/r/leetcode/comments/14zebss/can_anyone_with_leetcode_premium_share_the_list/)\n\n'
    '## [Google-101](https://drive.google.com/file/d/1YD9kosAAXeHZx49QELYy-52dWZD0sl6-/view?usp=sharing)\n\n'
]

with open(json_file, 'r') as f:
    data = json.load(f)

    visited = set()

    for i in range(len(data)):
        problem = data[i]
        lines.append(f"{i + 1}. {problem['links']['leetcode']}\n")
        visited.add(problem['links']['leetcode'])


    lines.append('\n\n')
    lines.append(f"## https://github.com/snehasishroy/leetcode-companywise-interview-questions/blob/master/google.csv\n\n")
    df = pd.read_csv(csv_file)
    sorted_df = df.sort_values(by='Frequency %', ascending=False)
    for index, row in sorted_df.iterrows():
        link = f"https://leetcode.com{row['URL']}"
        
        if link in visited:
            continue
        
        i += 1
        lines.append(f"{i + 1}. {link}\n")

    with open(destination, 'w') as f:
        f.writelines(lines)


