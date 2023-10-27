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

TAG_MATH = 'Math'
TAG_BIT = 'Bit Manipulation'
TAG_SIM = 'Simulation'
TAG_DESIGN = 'Design'
TAG_GREEDY = 'Greedy'
TAG_DP = 'Dynamic Programming'
TAG_ARY = 'Array'
TAG_STR = 'String'
TAG_TP = 'Two Pointers'
TAG_BFS = 'Breadth-First Search'
TAG_BT = 'Backtracking'
TAG_DFS = 'Depth-First Search'
TAG_DC = 'Divide and Conquer'
TAG_BINARY_SEARCH = 'Binary Search'
TAG_BINARY_SEARCH_TREE = 'Binary Search Tree'
TAG_LINKED_LIST = 'Linked List'
TAG_HASH = 'Hash Table'
TAG_UNION_FIND = 'Union Find'
TAG_TRIE = 'Trie'

CATEGORY_OTHER = 'Other'

ALL_CATEGORIES = [TAG_MATH, TAG_BIT, TAG_SIM, TAG_DESIGN, TAG_LINKED_LIST, TAG_BINARY_SEARCH, TAG_TP,
                  TAG_BFS, TAG_BT, TAG_DC, TAG_DFS, TAG_HASH, TAG_GREEDY, TAG_DP, TAG_BINARY_SEARCH_TREE, 
                  TAG_UNION_FIND, TAG_TRIE, TAG_STR, TAG_ARY] + [CATEGORY_OTHER]

LANGUAGE = {
    'cpp': 'c++',
    'py': 'python',
    'java': 'java'
}

SUB_DIRECTORIES = ['leetcode', 'lintcode']

class Markdown:
    @staticmethod 
    def escape(content) -> str:
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

    @staticmethod 
    def paragraph(f, content):
        for line in content:
            f.write(str(line) + "<br/>\n")
        f.write("\n")

    @staticmethod
    def code(f, content, lang="shell"):
        f.write(f"```{lang}\n")
        for line in content:
            f.write(str(line) + "\n")
        f.write("```\n\n")

    @staticmethod 
    def bullet(f, content):
        for line in content:
            f.write("- " + str(line) + "\n")
        f.write("\n")

    @staticmethod 
    def title1(f, conent):
        f.write('# ' + str(conent) + "\n")

    @staticmethod 
    def title2(f, conent):
        f.write('## ' + str(conent) + "\n")

    @staticmethod
    def table_row(f, contents):
        content = ' | '.join([str(content) for content in contents])
        f.write("| " + content + " |" + "\n")

    @staticmethod
    def table_header(f, headers):
        Markdown.table_row(f, headers)
        Markdown.table_row(f, ['-----'] * len(headers))
    
    @staticmethod
    def table_footer(f):
        f.write("\n")

    @staticmethod 
    def table_content(f, directories, categories):
        
        def search_tag(tags):
            size = len(ALL_CATEGORIES)
            index = size - 1
            tags = tags.split(', ')
            for tag in tags:
                for i in range(size):
                    c = ALL_CATEGORIES[i]
                    if c.lower() in tag.lower():
                        index = min(i, index)

            return ALL_CATEGORIES[index]

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
                    
                    category = search_tag(category_match.group(1)) if category_match else CATEGORY_OTHER
                    time = time_match.group(1) if time_match else '-'
                    space = space_match.group(1) if space_match else '-'
                    ref = link_match.group(1) if link_match else '-'                
                    note = note_match.group(1) if note_match else '-'

                    solution = Solution(source, number, name, extension, category, time, space, note, ref)
                    category_set[solution.tag].append(solution)

                    lang = LANGUAGE[extension] if extension in LANGUAGE else extension
                    code = Markdown.link(lang, path)
                    solution_set[solution.key].append(code)
        
        for category in categories:
            headers = ['Problem', 'Solution', 'Time', 'Space', 'Note', 'Ref']
            Markdown.title2(f, category)

            category_tag = "-".join(category.lower().split())
            if len(category_set[category_tag]) == 0:
                continue

            Markdown.table_header(f, headers)
            sorted_solutions = sorted(category_set[category_tag], key=lambda s: (s.source, s.note, s.name, s.number))
            for solution in sorted_solutions:

                if solution.key not in solution_set:
                    continue

                codes = ', '.join(solution_set[solution.key])

                contents = [
                    solution.problem_link,
                    codes,
                    solution.time,
                    solution.space,
                    solution.note,
                    solution.ref_link,
                    ]
    
                Markdown.table_row(f, contents) 
                del solution_set[solution.key]

            Markdown.table_footer(f)
    
    @staticmethod
    def link(content, link):
        return f"[{content}]({link})"

    @staticmethod
    def tag(content):
        category_tag = "-".join(content.lower().split())
        return Markdown.link(content, f'#{category_tag}')

class Solution:
    def __init__(self, source, number, name, extension, category, time, space, note, ref) -> None:
        self.source = source
        self.number = number
        self.name = name
        self.extension = extension
        self.category = category
        self.time = Markdown.escape(time)
        self.space = Markdown.escape(space)
        self.note = Markdown.escape(note)
        self.ref = ref  
        self.roman_rex = re.compile(r"(?:(?<=\W)|^)M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", re.IGNORECASE)

    @property
    def tag(self) -> str:
        return "-".join(self.category.lower().split())
    
    @property
    def title(self) -> str:
        problem = self.name.replace('-', ' ')
        orginal_title = f'{self.source}-{self.number}. {problem}'.title()
        return re.sub(self.roman_rex, lambda x: x.group(0).upper(), orginal_title)

    @property
    def key(self) -> str:
        return f'{self.source}-{self.name}'

    @property
    def problem_link(self) -> str:
        if self.source.lower() == 'leetcode':
            return Markdown.link(self.title, f'https://leetcode.com/problems/{self.name}/description/')
        if self.source.lower() == 'lintcode':
            return Markdown.link(self.title, f'https://www.lintcode.com/problem/{self.name}')
        else:
            return f'#'
        
    @property
    def ref_link(self) -> str:
        if re.search(r'(youtube\.com|youtu\.be)', self.ref):
            return Markdown.link('Video', self.ref)
        else:
            return f'-'

    def __repr__(self) -> str:
        return f'{self.source}-{self.number}({self.extension})'

    def __str__(self) -> str:
        return f'{self.source}-{self.number}({self.extension})'

    @staticmethod
    def statistic(directories) -> int:
        statistic_set = collections.defaultdict(list)

        for source in directories:
            files = sorted(os.listdir(source), key=lambda file: (int(file.split(".")[0]), file[file.rfind(".") + 1: ]))
            for file_name in files:
                first_dot = file_name.find('.')
                last_dot = file_name.rfind('.')
                name = file_name[first_dot + 1: last_dot]
                extension = file_name[last_dot + 1: ]
                number = file_name[: first_dot]
                solution = Solution(source, number, name, extension, '-', '-', '-', '-', '-')
                statistic_set[solution.name].append(solution)

        for key, val in statistic_set.items():
            source = set(val)
            if len(source) > 2:
                print(f"{key.replace('-', ' ').title()}: {val}")

        return len(statistic_set)

if __name__ == "__main__":
   with open("README.md", "w") as f:
        
        Markdown.title1(f, "算法/Algorithm")
        Markdown.paragraph(f, [
            "我个人的力扣答案, **公众号:GeekPal**",
            "这是一个持续更新的开源项目",
            "",
            "My personal leetcode answers",
            "This is a **continually updated** open source project",
        ])

        Markdown.title2(f, "软件/Softwares")
        Markdown.bullet(f, [
            Markdown.link('Anki', 'https://apps.ankiweb.net/'),
            Markdown.link('Tldraw', 'https://www.tldraw.com/'),
            Markdown.link('OBS', 'https://www.tldraw.com/')
        ])

        Markdown.title2(f, '脚本/Script')
        Markdown.code(f, [
            "pip install -r requirements.txt",
            "python problem.py <leetcode/lintcode> [-l java|cpp|python(default)] [-t]",
            "# 例如(e.g.):",
            "python problem.py https://leetcode.com/problems/online-stock-span/",
            "python problem.py https://www.lintcode.com/problem/92 -l cpp",
        ])

        Markdown.title2(f, "文章/Articles")
        Markdown.bullet(f, [
            Markdown.link('Blog博客', 'http://geemaple.github.io/category/#Algobase'),
            Markdown.link('Youtube频道', 'https://www.youtube.com/@GeekPal')
        ])

        Markdown.title2(f, "书籍/Books")
        Markdown.bullet(f, [
            "《算法技术手册》/ Algorithms in a Nutshell",
            "《STL源码剖析》/ The Annotated STL Sources",
            "《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition",
            "《数学之美》(A chinese version book by Doctor Wujun)",
            "《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)"
        ])
      
        Markdown.title2(f, Markdown.link('Category', 'category'))
        Markdown.bullet(f, [Markdown.tag(c) for c in ALL_CATEGORIES])
        Markdown.table_content(f, SUB_DIRECTORIES, ALL_CATEGORIES)
          
        Markdown.title2(f, "其他/Other")
        Markdown.paragraph(f, [
            f"Total sovled: **{Solution.statistic(SUB_DIRECTORIES)}**",
            f'Auto updated at: **{datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")}**'])