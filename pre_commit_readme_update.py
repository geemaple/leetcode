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
import collections
from functools import lru_cache
from datetime import datetime 

TAG_MATH = 'Math'
TAG_PROB = 'Probability'
TAG_BIT_OP = 'Bit Manipulation'
TAG_SIM = 'Simulation'
TAG_DESIGN = 'Design'
TAG_GREEDY = 'Greedy'
TAG_DP = 'Dynamic Programming'
TAG_BS = 'Binary Search'
TAG_LINKED_LIST = 'Linked List'
TAG_HASH = 'Hash Table'
TAG_STACK = 'Stack'
TAG_MONO_STACK = 'Monotonic Stack'
TAG_QUEUE = 'Queue'
TAG_MONO_QUEUE = 'Monotonic Queue'
TAG_HEAP = 'Heap'
TAG_2P = 'Two Pointers'
TAG_SWIN = 'Sliding Window'
TAG_SORT = 'Sorting'
TAG_COUNT = 'Counting'
TAG_QSEL = 'Quickselect'
TAG_DC = 'Divide and Conquer'
TAG_BFS = 'Breadth-First Search'
TAG_DFS = 'Depth-First Search'
TAG_TSORT = 'Topological Sort'
TAG_BTRACK = 'Backtracking'
TAG_LSWEEP = 'Line Sweep'
TAG_ORDERED_SET = 'Ordered Set'
TAG_BST = 'Binary Search Tree'
TAG_BIT = 'Binary Indexed Tree'
TAG_SEGMENT_TREE = 'Segment Tree'
TAG_UNION_FIND = 'Union Find'
TAG_TRIE = 'Trie'

FOLD_TAG_ARY = 'Array'
FOLD_TAG_STR = 'String'
FOLD_TAG_SET = 'Set'
FOLD_TAG_TREE = 'Tree'
FOLD_TAG_GRAPH = 'Graph'
FOLD_TAG_RECURSION = 'Recursion'

CATEGORY_OTHER = 'Other'

ivars = globals()
SHOW_CATEGORIES = [ivars[n] for n in ivars if n.startswith('TAG')]
FOLD_STRUCTURES = [ivars[n] for n in ivars if n.startswith('FOLD_TAG')]
ALL_CATEGORIES =  SHOW_CATEGORIES + FOLD_STRUCTURES + [CATEGORY_OTHER]
TAG_MAP = {
    TAG_MATH: [TAG_PROB, TAG_BIT_OP, TAG_DP],
    TAG_STACK: [TAG_MONO_STACK],
    TAG_QUEUE: [TAG_MONO_QUEUE],
    TAG_2P: [TAG_SWIN],
    TAG_SORT: [TAG_COUNT],
    TAG_BFS: [TAG_TSORT],
    TAG_DFS: [TAG_BTRACK, TAG_TSORT],
}

TAG_IGNORE = r'-|Interactive'

TAG_REGEX = {
    TAG_MATH: r'Math|Number Theory',
    TAG_DESIGN: r'^Design$|Iterator',
    TAG_BS: r'^Binary Search$|Binary Search on Answer',
    TAG_2P: r'^Two Pointers$|Same Direction Two Pointers',
    TAG_BFS: r'Breadth-First Search|Breadth First Search|BFS',
    TAG_DFS: r'Depth-First Search|Depth First Search|DFS',
    TAG_DP: r'DP$|Dynamic Programming|Memoization',
    TAG_SORT: r'^Sort$|^Sorting$|Merge Sort|Bucket Sort',
    TAG_PROB: r'Randomized|Rejection Sampling|Reservoir Sampling|Probability and Statistics',
    TAG_QUEUE: r'^Queue$',
    TAG_HEAP: r'^Heap$|Priority Queue',
    TAG_HASH: r'^Hash Table$|Hash Function',
    FOLD_TAG_TREE: r'^Tree$|Binary Tree',
    FOLD_TAG_ARY: r'^Array$|^Matrix$|Prefix Sum',
}

LANGUAGE = {
    'cpp': 'c++',
    'py': 'python3',
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
            f.write(str(line) + "\n\n")

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
        f.write('# ' + str(conent) + "\n\n")

    @staticmethod 
    def title2(f, conent):
        f.write('## ' + str(conent) + "\n\n")

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
                match_category = set([x for x in ALL_CATEGORIES if re.search(TAG_REGEX.get(x, rf"^{x}$"), tag, re.IGNORECASE)])
                if len(match_category) > 0:
                    match_all.update(match_category)
                elif not re.search(TAG_IGNORE, tag):
                    print(f'{tag}/[{solution.tags}] - {solution}')

            duplicates = {x for x in match_all if x in TAG_MAP and any(sub in match_all for sub in TAG_MAP[x])}
            fold_category = set([x for x in (match_all - duplicates) if x in FOLD_STRUCTURES])
            show_category = match_all - duplicates - fold_category

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
            
            Markdown.table_header(f, ['Update', f'Problem({len(solution_set)})', 'Solution', 'Tag', 'Time', 'Space', 'Ref'])
            sorted_solutions = sorted(category_set[category], key=lambda s: (s.update, s.source, int(s.number)))
            
            for solution in sorted_solutions:
                if solution.key not in solution_set:
                    continue

                codes = ', '.join(sorted(solution_set[solution.key]))

                contents = [
                    solution.update.strftime('%Y-%m'),
                    solution.problem_link,
                    codes,
                    category,
                    solution.time,
                    solution.space,
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

                    mod_time = os.path.getmtime(path)
                    mod_datetime = datetime.fromtimestamp(mod_time)

                    all_solution.append(Solution(path, source, number, name, extension, tags, time, space, note, ref, mod_datetime))

            print(f'{source} files = {count}')
        return all_solution
    
    @staticmethod
    def statistic() -> int:
        statistic_set = collections.defaultdict(set)
        year_archive = collections.defaultdict(set)
        visited = set()

        res = []
        for s in Solution.all():
            statistic_set[s.name].add(s)
            if s not in visited:
                visited.add(s)
                year_archive[s.update.year].add(s)

        for year in sorted(year_archive.keys()):
            res.append(f'**{year}:** {len(year_archive[year])} problems')

        count = 0
        duplicates = []
        for key, solutions in statistic_set.items():
            source = set([s.source for s in solutions])
            if len(source) > 1:
                count += 1
                duplicates.append(f"- **\"{key}\"** ({', '.join(source)})")

        if len(duplicates) > 0:
            res.append(f"**Duplicates:**")
            res += duplicates
                
        res.append(f"**Total:** {len(statistic_set)} problems")
        res.append(f"**Updated:** {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
        return res

    def __init__(self, path, source, number, name, extension, tags, time, space, note, ref, modify_date) -> None:
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
        self.update = modify_date
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
            "My Personal LeetCode Solutions",
            "This is an open-source project that is continually updated"] + Solution.statistic())

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