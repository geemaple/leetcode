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

LANGUAGE = {
    'cpp': 'c++',
    'py': 'python',
}

class Solution:
    def __init__(self, source, number, problem, category, time, space, ref) -> None:
        self.source = source
        self.number = number
        self.problem = problem
        self.category = category
        self.time = time
        self.space = space
        self.ref = ref
        
    @property
    def tag(self) -> str:
        return "-".join(self.category.lower().split())
    
    @property
    def name(self) -> str:
        return f'{self.source}-{self.number}.{self.problem}'

    @property
    def link(self) -> str:
        if self.source.lower() == 'leetcode':
            return f'https://leetcode.com/problems/{self.name}/description/'
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

def table_row(f, content):
    f.write("| " + content + " |" + "\n")

def table_header(f, headers):
    header_mark = ' | '.join(headers)
    seperator = ' | '.join(['----' for _ in range(len(headers))])
    table_row(f, header_mark)
    table_row(f, seperator)

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
                
                category = category_match.group(1) if category_match else 'other'
                time = time_match.group(1) if time_match else '-'
                space = space_match.group(1) if space_match else '-'
                ref = link_match.group(1) if link_match else '-'                

                solution = Solution(source, number, name, category, time, space, ref)
                category_set[solution.tag].append(solution)

                lang = LANGUAGE[extension] if extension in LANGUAGE else extension
                code = link_mark(lang, path)
                solution_set[solution.name].append(code)
    
    title2(f, "进度/Progress")
    paragraph(f, [f'Total sovled **{len(solution_set)}**'])
    
    for category in categories:
        headers = ['Problem', 'Solution', 'Time', 'Space', 'Ref']
        title2(f, category)

        hyphen_tag = "-".join(category.lower().split())
        if len(category_set[hyphen_tag]) == 0:
            continue

        table_header(f, headers)
        for solution in category_set[hyphen_tag]:

            if solution.name not in solution_set:
                continue

            content = [
                link_mark(solution.name, solution.link),
                ', '.join(solution_set[solution.name]),
                solution.time,
                solution.space,
                solution.ref]
   
            row = ' | '.join([cell for cell in content])
            table_row(f, row) 
            del solution_set[solution.name]


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
            "这是一个持续更新的开源项目",
            "<br/>",
            "My personal leetcode answers<br/>",
            "This is a **continually updated** open source project",
        ])

        title2(f, "软件/Softwares")
        bullet(f, [
            link_mark('Anki', 'https://apps.ankiweb.net/')
        ])

        title2(f, '脚本/Script')
        paragraph(f, [
            "```",
            "pip install -r requirements.txt",
            "python problem.py <leetcode/lintcode> -l java|cpp|python",
            "# 例如(For Example):",
            "python problem.py https://leetcode.com/problems/online-stock-span/ #python is default here",
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

        categories = ["Math", "Bit", "Design", "Array and String", "Two Pointers", "Linked List",
                      "Binary Search", "Divide and Conquer", "Tree Traversal", "Graph Traversal",
                      "Backtracking", "Hash Table", "Queue", "Heap", "Stack", "Sweep Line", "Greedy"
                      "Dynamic Programming", "Red Black Tree", "Greedy", "Union Find", "Trie", "Other"]
      
        title2(f, link_mark('Category', 'category'))
        bullet(f, [tag_mark(c) for c in categories])

        table_content(f, ['leetcode', 'lintcode'], categories)
          
        f.write(f"\n Last updated: {datetime.datetime.now()}\n")


if __name__ == "__main__":
    update_readme("README.md")