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
from functools import lru_cache

TAG_MATH = 'Math'
TAG_BIT = 'Bit Manipulation'
TAG_SIM = 'Simulation'
TAG_DESIGN = 'Design'
TAG_GREEDY = 'Greedy'
TAG_DP = 'Dynamic Programming'
TAG_ARY = 'Array'
TAG_STR = 'String'
TAG_STACK = 'Stack'
TAG_TP = 'Two Pointers'
TAG_SW = 'Sliding Window'
TAG_SORT = 'Sorting'
TAG_COUNT = 'Counting'
TAG_BFS = 'Breadth-First Search'
TAG_BT = 'Backtracking'
TAG_DFS = 'Depth-First Search'
TAG_DC = 'Divide and Conquer'
TAG_BINARY_SEARCH = 'Binary Search'
TAG_BINARY_SEARCH_TREE = 'Binary Search Tree'
TAG_LINKED_LIST = 'Linked List'
TAG_PQ = 'Priority Queue'
TAG_HASH = 'Hash Table'
TAG_UNION_FIND = 'Union Find'
TAG_TRIE = 'Trie'
TAG_SEGMENT_TREE = 'Segment Tree'
TAG_TREE = 'Tree'
TAG_GRAPH = 'Graph'
TAG_BFS_TS = 'Topological Sort'

CATEGORY_OTHER = 'Other'

SHOW_CATEGORIES = [TAG_MATH, TAG_BIT, TAG_SIM, TAG_DESIGN, TAG_BINARY_SEARCH, TAG_LINKED_LIST, TAG_TP, TAG_SW, TAG_STACK, TAG_SORT, TAG_COUNT,
                  TAG_GREEDY, TAG_DP, TAG_BT, TAG_DC, TAG_BFS, TAG_BFS_TS, TAG_DFS, TAG_PQ, TAG_UNION_FIND, TAG_TRIE, TAG_SEGMENT_TREE]

FOLD_STRUCTURES = [TAG_ARY, TAG_STR, TAG_TREE, TAG_HASH, TAG_GRAPH]
ALL_CATEGORIES =  SHOW_CATEGORIES + FOLD_STRUCTURES + [CATEGORY_OTHER]

TAG_IGNORE = r'-|Iterator|Interactive'

TAG_REGEX = {
    TAG_BFS: r'Breadth-First Search|Breadth First Search|BFS',
    TAG_DFS: r'Depth-First Search|Depth First Search|DFS',
    TAG_DP: r'Dynamic Programming|DP|Memoization',
    TAG_TREE: r'^Tree$|Binary Indexed Tree|Binary Tree|Binary Search Tree',
    TAG_ARY: r'Array|Matrix|Prefix Sum',
    TAG_SORT: r'^Sort$|Sorting|Bucket Sort',
    TAG_MATH: r'Math|Number Theory|Randomized'
}

LANGUAGE = {
    'cpp': 'c++',
    'py': 'python',
    'java': 'java'
}

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
    def table_content(f, categories):
        print('----table content----')
        def search_tag(solution):
            tags = solution.tags
            match_all = set()

            for tag in tags.split(', '):
                match_category = set([x for x in ALL_CATEGORIES if re.search(TAG_REGEX.get(x, x), tag, re.IGNORECASE)])
                if len(match_category) > 0:
                    match_all.update(match_category)
                elif not re.search(TAG_IGNORE, tag):
                    print(f'{tag}/[{solution.tags}] - {solution}')

            fold_category = set([x for x in match_all if x in FOLD_STRUCTURES])
            show_category = match_all - fold_category

            if len(show_category) > 0:
                return set(show_category)

            if len(fold_category) > 0:
                return set(fold_category)

            return {CATEGORY_OTHER}

        category_set = collections.defaultdict(list)

        for s in Solution.all():
            for category in search_tag(s):
                category_set[category].append(s)                                     
        
        for category in categories:
            if len(category_set[category]) == 0:
                continue
            
            Markdown.title2(f, category)
            solution_set = collections.defaultdict(list)
            for s in category_set[category]:
                solution_set[s.key].append(s.local_path)
            
            Markdown.table_header(f, [f'Problem({len(solution_set)})', 'Solution', 'Time', 'Space', 'Note', 'Ref'])
            sorted_solutions = sorted(category_set[category], key=lambda s: (s.source, int(s.number)))
            
            for solution in sorted_solutions:
                if solution.key not in solution_set:
                    continue

                codes = ', '.join(sorted(solution_set[solution.key]))

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
    @staticmethod
    @lru_cache()
    def all(directories=['leetcode', 'lintcode']) -> int:

        all_solution = []
        for source in directories:
            count = 0
            for file_name in os.listdir(source):
                if file_name.startswith('.'):
                    continue

                count += 1
                first_dot = file_name.find('.')
                last_dot = file_name.rfind('.')
                name = file_name[first_dot + 1: last_dot]
                extension = file_name[last_dot + 1: ]
                number = file_name[: first_dot]
                
                path = os.path.join(f'./{source}/{file_name}')

                with open(path, 'r') as code:
                    text = code.read()
                    tag_match = re.search(r"Tag: (.+)", text)
                    time_match = re.search(r"Time: (.+)", text)
                    space_match = re.search(r"Space: (.+)", text)
                    link_match = re.search(r"Ref: (.+)", text)
                    note_match = re.search(r"Note: (.+)", text)
                    
                    tags = tag_match.group(1) if tag_match else '-'
                    time = time_match.group(1) if time_match else '-'
                    space = space_match.group(1) if space_match else '-'
                    ref = link_match.group(1) if link_match else '-'                
                    note = note_match.group(1) if note_match else '-'
                    all_solution.append(Solution(path, source, number, name, extension, tags, time, space, note, ref))

            print(f'{source} files = {count}')
        return all_solution
    
    @staticmethod
    def statistic() -> int:
        statistic_set = collections.defaultdict(list)

        for s in Solution.all():
            statistic_set[s.name].append(s)

        for key, solutions in statistic_set.items():
            source = set(solutions)
            if len(source) > 1:
                print(f"{key}: {solutions}")

        print(f'solved = {len(statistic_set)}')
        return len(statistic_set)

    def __init__(self, path, source, number, name, extension, tags, time, space, note, ref) -> None:
        self.path = path
        self.source = source
        self.number = number
        self.name = name
        self.extension = extension
        self.tags = tags
        self.time = Markdown.escape(time)
        self.space = Markdown.escape(space)
        self.note = Markdown.escape(note)
        self.ref = ref  
        self.roman_rex = re.compile(r"(?:(?<=\W)|^)M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", re.IGNORECASE)

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
    def local_path(self) -> str:
        lang = LANGUAGE[self.extension] if self.extension in LANGUAGE else self.extension
        return Markdown.link(lang, self.path) 
        
    @property
    def ref_link(self) -> str:
        if re.search(r'(youtube\.com|youtu\.be)', self.ref):
            return Markdown.link('Video', self.ref)
        else:
            return f'-'

    def __eq__(self, other):
        return isinstance(other, Solution) and self.key == other.key

    def __hash__(self):
        return hash(self.key)

    def __repr__(self) -> str:
        return f'{self.title}.{self.extension}'

    def __str__(self) -> str:
        return self.__repr__()

if __name__ == "__main__":
   with open("README.md", "w") as f:
        
        Markdown.title1(f, "算法/Algorithm")
        Markdown.paragraph(f, [
            "我个人的力扣答案, **公众号:GeekPal**",
            "这是一个持续更新的开源项目",
            "",
            "My personal leetcode answers",
            "This is a **continually updated** open source project",
            "",
            f"Total sovled: **{Solution.statistic()}**",
            f"Auto updated at: **{datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}**"
        ])

        Markdown.title2(f, "软件/Softwares")
        Markdown.bullet(f, [
            Markdown.link('Anki', 'https://apps.ankiweb.net/'),
            Markdown.link('Tldraw', 'https://www.tldraw.com/'),
            Markdown.link('OBS', 'https://www.tldraw.com/'),
            Markdown.link('Leetcode中英网站切换', 'https://greasyfork.org/en/scripts/478450-leetcode-cn-en-site-switcher'),
        ])

        Markdown.title2(f, '脚本/Script')
        Markdown.code(f, [
            "pip install -r requirements.txt",
            "python problem.py <leetcode/lintcode> [-l java|cpp|python(default)] [-t]",
            "# 例如(e.g.):",
            "python problem.py https://leetcode.com/problems/online-stock-span/",
            "python problem.py https://www.lintcode.com/problem/92 -l cpp",
        ])

        Markdown.title2(f, "链接/Links")
        Markdown.bullet(f, [
            Markdown.link('本人博客', 'https://blog.mogoal.com/category/#Algorithm'),
            Markdown.link('极客时间', 'https://github.com/geektime-geekbang/algorithm-1'),
            Markdown.link('LeetCode 101', 'https://github.com/changgyhub/leetcode_101'),
        ])

        Markdown.title2(f, "书籍/Books")
        Markdown.bullet(f, [
            "《算法技术手册》/ Algorithms in a Nutshell",
            "《STL源码剖析》/ The Annotated STL Sources",
            "《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition",
            "《数学之美》(A chinese version book by Doctor Wujun)",
            "《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)"
            ""
        ])

        Markdown.title2(f, Markdown.link('Category', 'category'))
        Markdown.bullet(f, [Markdown.tag(c) for c in SHOW_CATEGORIES])
        Markdown.table_content(f, ALL_CATEGORIES)