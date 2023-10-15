# this is a client-side hook 
# add the following command to pre-commit in the .git/hooks
# don't foget to make it executable `chmod +x .git/hooks/pre-commit`

# #!/bin/bash

# # Update the README file with the python script
# python pre_commit_readme_update.py

# # Add the README file to the git index
# git add README.md

import os
import re
import datetime
import collections

TAG_ARRAY = 'Array'
TAG_BIT = 'Bit Manipulation'
TAG_MATH = 'Math'
TAG_GREEDY = 'Greedy'
TAG_DP = 'Dynamic Programming'
TAG_HASH = 'Hash Table'
TAG_DESIGN = 'Design'
TAG_DFS = 'Depth-First Search'
TAG_BFS = 'Breadth-First Search'
TAG_BINARY_SEARCH = 'Binary Search'
TAG_BINARY_SEARCH_TREE = 'Binary Search Tree'
TAG_UNION_FIND = 'Union Find'
TAG_LINKED_LIST = 'Linked List'
TAG_TRIE = 'Trie'

TAG_OTHER = 'Other'

LANGUAGE = {
    'cpp': 'c++',
    'py': 'python',
    'java': 'java'
}

class Solution:
    def __init__(self, source, number, problem, category, time, space, note, ref) -> None:
        self.source = source
        self.number = number
        self.problem = problem
        self.category = self.markdown_escape(category)
        self.time = self.markdown_escape(time)
        self.space = self.markdown_escape(space)
        self.note = self.markdown_escape(note)
        self.ref = ref

    def markdown_escape(self, content) -> str:
        escape_table = {
            '\\': '\\',
            '`': '\\`',
            '*': '\\*',
            '_': '\\_',
            '{': '\\{',
            '}': '\\}',
            '[': '\\[',
            ']': '\\]',
            '(': '\\(',
            ')': '\\)',
            '#': '\\#',
            '+': '\\+',
            '-': '\\-',
            '.': '\\.',
            '!': '\\!',
            '|': '\\|',
        }

        escaped_text = content.translate({ord(key): value for key, value in escape_table.items()})
        return escaped_text
  
        
    @property
    def tag(self) -> str:
        return "-".join(self.category.lower().split())
    
    @property
    def name(self) -> str:
        return f'{self.source}-{self.number}.{self.problem}'

    @property
    def link(self) -> str:
        if self.source.lower() == 'leetcode':
            return f'https://leetcode.com/problems/{self.problem}/description/'
        if self.source.lower() == 'lintcode':
            return f'https://www.lintcode.com/problem/{self.number}'
        else:
            return f'#'

    def __repr__(self) -> str:
        return f'{self.name} {self.category} {self.time} {self.space} {self.ref}'

    def __str__(self) -> str:
        return f'{self.name} {self.category} {self.time} {self.space} {self.ref}'

def paragraph(f, content):
    for line in content:
        f.write(str(line) + "\n")
    f.write("\n")

def bullet(f, content):
    for line in content:
        f.write("- " + str(line) + "\n")
    f.write("\n")

def title1(f, conent):
    f.write('# ' + str(conent) + "\n")

def title2(f, conent):
    f.write('## ' + str(conent) + "\n")

def table_row(f, contents):
    content = ' | '.join([str(content) for content in contents])
    f.write("| " + content + " |" + "\n")

def table_header(f, headers):
    table_row(f, headers)
    table_row(f, ['-----'] * len(headers))

def search_tag(tags):
    tags = tags.split(', ')
    for tag in tags:
        if any(ext.lower() in tag.lower() for ext in [TAG_ARRAY]):
            continue

        if any(ext.lower() in tag.lower() for ext in ['DP', 'Backpack', TAG_DP]):
            return TAG_DP
        else:
            return tag
    
def table_content(f, directories, categories):
    
    category_set = collections.defaultdict(list)
    solution_set = collections.defaultdict(list)

    for source in directories:
        files = sorted(os.listdir(source), key=lambda file: (int(file.split(".")[0]), file[file.rfind(".") + 1: ]))
        for file_name in files:
            first_dot = file_name.find('.')
            last_dot = file_name.rfind('.')
            name = file_name[first_dot + 1: last_dot]
            extension = file_name[last_dot + 1: ]
            number = file_name[: first_dot]
            
            path = os.path.join(f'./{source}/{file_name}')

            with open(path, 'r') as code:
                text = code.read()
                category_match = re.search(r"Category: (.+)", text)
                time_match = re.search(r"Time: (.+)", text)
                space_match = re.search(r"Space: (.+)", text)
                link_match = re.search(r"Ref: (.+)", text)
                note_match = re.search(r"Note: (.+)", text)
                
                category = search_tag(category_match.group(1)) if category_match else TAG_OTHER
                time = time_match.group(1) if time_match else '-'
                space = space_match.group(1) if space_match else '-'
                ref = link_match.group(1) if link_match else '-'                
                note = note_match.group(1) if note_match else '-'

                solution = Solution(source, number, name, category, time, space, note, ref)
                category_set[solution.tag].append(solution)

                lang = LANGUAGE[extension] if extension in LANGUAGE else extension
                code = link_mark(lang, path)
                solution_set[solution.name].append(code)

    solved_problems = len(solution_set)
    
    for category in categories:
        headers = ['Problem', 'Solution', 'Time', 'Space', 'Note', 'Ref']
        title2(f, category)

        hyphen_tag = "-".join(category.lower().split())
        if len(category_set[hyphen_tag]) == 0:
            continue

        table_header(f, headers)
        for solution in category_set[hyphen_tag]:

            if solution.name not in solution_set:
                continue

            contents = [
                link_mark(solution.name, solution.link),
                ', '.join(solution_set[solution.name]),
                solution.time,
                solution.space,
                solution.note,
                solution.ref,
                ]
   
            table_row(f, contents) 
            del solution_set[solution.name]

    return solved_problems

def link_mark(content, link):
    return f"[{content}]({link})"

def tag_mark(content):
    hyphen_tag = "-".join(content.lower().split())
    return f"[{content}](#{hyphen_tag})"

def update_readme(file_name):
    with open(file_name, "w") as f:
        
        title1(f, "算法/Algorithm")
        paragraph(f, [
            "我个人的力扣答案, ```#公众号:GeekPal```<br/>",
            "这是一个持续更新的开源项目<br/>",
            "<br/>",
            "My personal leetcode answers<br/>",
            "This is a **continually updated** open source project",
        ])

        title2(f, "软件/Softwares")
        bullet(f, [
            link_mark('Anki', 'https://apps.ankiweb.net/'),
            link_mark('Tldraw', 'https://www.tldraw.com/'),
            link_mark('OBS', 'https://www.tldraw.com/')
        ])

        title2(f, '脚本/Script')
        paragraph(f, [
            "```",
            "pip install -r requirements.txt",
            "python problem.py <leetcode/lintcode> -l java|cpp|python(default)",
            "# 例如(e.g.):",
            "python problem.py https://leetcode.com/problems/online-stock-span/",
            "python problem.py https://www.lintcode.com/problem/92 -l cpp",
            "```"
        ])

        title2(f, "文章/Articles")
        bullet(f, [
            link_mark('博客结题报告', 'http://geemaple.github.io/'),
            link_mark('公众号解题报告', 'https://mp.weixin.qq.com/mp/appmsgalbum?action=getalbum&album_id=1416970062002601985&__biz=MzI1NjA4ODU4NQ==#wechat_redirect')
        ])

        title2(f, "书籍/Books")
        bullet(f, [
            "《算法技术手册》/ Algorithms in a Nutshell",
            "《STL源码剖析》/ The Annotated STL Sources",
            "《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition",
            "《数学之美》(A chinese version book by Doctor Wujun)",
            "《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)"
        ])

        categories = [TAG_MATH, TAG_BIT, TAG_DESIGN, "Two Pointers", TAG_LINKED_LIST,
                      TAG_BINARY_SEARCH, "Divide and Conquer", TAG_DFS, TAG_BFS,
                      "Backtracking", TAG_HASH, "Queue", "Heap", "Stack", "Sweep Line", TAG_GREEDY,
                      TAG_DP, TAG_BINARY_SEARCH_TREE, TAG_UNION_FIND, TAG_TRIE, TAG_OTHER]
      
        title2(f, link_mark('Category', 'category'))
        bullet(f, [tag_mark(c) for c in categories])

        solved_problems = table_content(f, ['leetcode', 'lintcode'], categories)
          
        title2(f, "进度/Progress")
        paragraph(f, [
            f'Total sovled **{solved_problems}**\n',
            f'Auto updated at: **{datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")}**'])

if __name__ == "__main__":
    update_readme("README.md")