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
from urllib.parse import urlparse
import random
from logger import Logger

TAG_MATH = 'Math'
TAG_PROB = 'Probability'
TAG_COMB = 'Combinatorics'
TAG_BIT_OP = 'Bit Manipulation'
TAG_BIT_MASK = 'Bitmask'
TAG_SIM = 'Simulation'
TAG_DESIGN = 'Design'
TAG_GREEDY = 'Greedy'
TAG_DP = 'Dynamic Programming'
TAG_GAME = 'Game Theory'
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
TAG_TOPOLOGICAL_SORT = 'Topological Sort'
TAG_SHORTEST_PATH = 'Shortest Path'
TAG_BTRACK = 'Backtracking'
TAG_LSWEEP = 'Line Sweep'
TAG_ORDERED_SET = 'Ordered Set'
TAG_BST = 'Binary Search Tree'
TAG_BIT = 'Binary Indexed Tree'
TAG_SEGMENT_TREE = 'Segment Tree'
TAG_UNION_FIND = 'Union Find'
TAG_TRIE = 'Trie'

MISC_TAG_ARY = 'Array'
MISC_TAG_STR = 'String'
MISC_TAG_SET = 'Set'
MISC_TAG_TREE = 'Tree'
MISC_TAG_GRAPH = 'Graph'
MISC_TAG_RECURSION = 'Recursion'

STUDY_TAG_PANDAS = 'Pandas'
STUDY_TAG_DATABASE = 'Database'

DEFAULT_TAG = 'Other'

ivars = globals()
SHOW_CATEGORIES = [ivars[n] for n in ivars if n.startswith('TAG')]
MISC_CATEGORIES = [ivars[n] for n in ivars if n.startswith('MISC_TAG')]
STUDY_CATEGORIES = [ivars[n] for n in ivars if n.startswith('STUDY_TAG')]
ALL_CATEGORIES =  SHOW_CATEGORIES + MISC_CATEGORIES + STUDY_CATEGORIES + [DEFAULT_TAG] 
TAG_MAP = {
    TAG_MATH: [TAG_PROB, TAG_BIT_OP, TAG_DP],
    TAG_DP: [TAG_GAME],
    TAG_STACK: [TAG_MONO_STACK],
    TAG_QUEUE: [TAG_MONO_QUEUE],
    TAG_2P: [TAG_SWIN],
    TAG_SORT: [TAG_COUNT],
    TAG_BFS: [TAG_TOPOLOGICAL_SORT, TAG_SHORTEST_PATH],
    TAG_DFS: [TAG_BTRACK, TAG_TOPOLOGICAL_SORT, TAG_SHORTEST_PATH],
}

TAG_IGNORE = r'-'

TAG_REGEX = {
    TAG_MATH: r'Math|Number Theory|Geometry',
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
    TAG_LSWEEP: r'^Line Sweep$|^Sweep Line$',
    MISC_TAG_TREE: r'^Tree$|Binary Tree',
    MISC_TAG_ARY: r'^Array$|^Matrix$|Prefix Sum',
    MISC_TAG_STR: r'^String$|^String Matching$',
}

EXTENSION = {
    '.cpp': 'c++',
    '.py': 'python3',
    '.java': 'java',
    '.sql': 'sql',
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
    def solution_table(f, categories):
        Logger.log('----tags----', Logger.BOLD)
        def search_tag(solution, unkown_tags):
            tags = solution.tags
            match_all = set()

            for tag in tags.split(','):
                tag = tag.strip()
                match_category = set([x for x in ALL_CATEGORIES if re.search(TAG_REGEX.get(x, rf"^{x}$"), tag, re.IGNORECASE)])
                if len(match_category) > 0:
                    match_all.update(match_category)
                elif not re.search(TAG_IGNORE, tag):
                    unkown_tags[solution] = tag

            duplicates = {x for x in match_all if x in TAG_MAP and any(sub in match_all for sub in TAG_MAP[x])}
            fold_category = set([x for x in (match_all - duplicates) if x in MISC_CATEGORIES])
            show_category = match_all - duplicates - fold_category
            study_category = show_category - show_category

            if len(study_category) > 0:
                return set(study_category)

            if len(show_category) > 0:
                return set(show_category)

            if len(fold_category) > 0:
                return set(fold_category)

            return {DEFAULT_TAG}

        category_set = collections.defaultdict(list)
        unkown_tags = {}
        solutions = Problem.all()
        for k, v in solutions.items():
            if '.vip' in [x.extension for x in v]:
                continue

            s = random.choice(v)
            for category in search_tag(s, unkown_tags):
                category_set[category] += v    

        for solution, tag in sorted(unkown_tags.items(), key=lambda x: x[1]):
            Logger.log(tag, Logger.WARNING, end=' ')
            Logger.log(f'[{solution.tags}]', Logger.OKBLUE, end=' ')
            Logger.log(solution, Logger.OKGREEN)

        for category in categories:
            if len(category_set[category]) == 0:
                continue

            Markdown.title2(f, category)
            solution_set = collections.defaultdict(list)
            for s in category_set[category]:
                solution_set[s.link].append(Markdown.link(s.language, s.path))

            Markdown.table_header(f, ['Link', f'Problem({len(solution_set)})', 'Solution', 'Tag', 'Time', 'Space', 'Ref'])
            sorted_solutions = sorted(category_set[category], key=lambda s: (s.source, s.title))

            for solution in sorted_solutions:
                if solution.link not in solution_set:
                    continue

                contents = [
                    Markdown.link(solution.link_title, solution.link),
                    solution.title,
                    ', '.join(sorted(solution_set[solution.link])),
                    category,
                    solution.time,
                    solution.space,
                    solution.ref,
                    ]

                Markdown.table_row(f, contents) 
                del solution_set[solution.link]

            Markdown.table_footer(f)

    @staticmethod
    def link(content, link):
        return f"[{content}]({link})"

    @staticmethod
    def tag(content):
        category_tag = "-".join(content.lower().split())
        return Markdown.link(content, f'#{category_tag}')

    @staticmethod
    def list_table(f):
        list_dir = './list'
        list_row = []
        list_stat = []
        solutions = Problem.all()
        all_problem = set()

        for file_name in os.listdir(list_dir):
            if not file_name.endswith('md'):
                continue

            file_path = os.path.join(list_dir, file_name)
            questions, dup, total = Problem.list(file_path)
            all_problem.update(questions)
            solved = set()
            vip = set()
            working = set()
            diff = set()
            missing = set()
            for q in questions:
                if q.number.isnumeric():
                    if q.link in solutions:
                        exensions = [x.extension for x in solutions[q.link]]
                        if '.vip' in exensions:
                            vip.add(q)
                        else:
                            sol = random.choice(solutions[q.link])
                            if q.source != sol.source:
                                diff.add(q)
                            solved.add(q)
                    else:
                        missing.add(q)
                else:
                    working.add(q)

            progress = f"{len(solved)}/{len(questions)}" 
            notes = f"{len(vip)} vip{'' if len(vip) == 1 else 's'}" if len(vip) > 0 else '-'     
            status = f'[{len(solved) * 100 // len(questions)}%]'
            if len(solved) + len(vip) == len(questions):
                status = '[✅]'
            elif len(working) > 0:
                status = '[🔲]'
            list_row.append((status, Markdown.link(file_name, file_path), progress, notes))
            list_stat.append((status, file_path, dup, solved, vip, missing, total))

            if len(diff) > 0 and (len(working) > 0 or len(solved) + len(vip) == len(questions)):
                Logger.log('----incorrect link----', Logger.WARNING)
                Logger.log(f'{file_path}:', Logger.OKBLUE, end=' ')
                Logger.log(f' {[q.title for q in diff]}', Logger.WARNING)


        Markdown.table_header(f, ['Status', 'List', 'Progress', 'Notes'])
        for row in sorted(list_row):
            Markdown.table_row(f, row)
        Markdown.table_footer(f)

        Logger.log('----list----', Logger.BOLD)
        for status, file_path, dup, solved, vip, missing, total in sorted(list_stat, reverse=True):
            finished = len(solved) + len(vip)
            duplicated = finished < total and len(dup) > 0
            
            Logger.log(f'{status}', end=' ')
            Logger.log(f'{finished:>3}/{total:<3}', Logger.OKGREEN, end=' ')
            Logger.log(f'{file_path:15}', Logger.OKBLUE, end=f' ')
            if duplicated:
                Logger.log(f'+dup:', Logger.WARNING, end=' ')
                if len(dup) > 3:
                    Logger.log(f'{random.sample(list(dup), 3)} ...', end=' ')
                else:
                    Logger.log(f'{dup}', end=' ')


            filter_vip = [x for x in vip if 'leetcode' in x.link]
            if len(filter_vip) > 0:
                if len(filter_vip) >= 3:
                    Logger.log(f'vip: {random.sample(list(filter_vip), 3)} ...', Logger.FAIL, end='')
                else:
                    Logger.log(f'vip: {filter_vip}', Logger.FAIL, end='')

            if len(missing) > 0:
                Logger.log(f'\n---{len(missing):3} TODO---:', Logger.WARNING, end=' ')
                if len(missing) >= 3:
                    Logger.log(f'{random.sample(list(missing), 3)} ...', end='')
                else:
                    Logger.log(f'{missing}', end='')


            Logger.log('')

        Logger.log(f'total list question = {len(all_problem)}', Logger.OKCYAN)

class Problem:
    @staticmethod
    def directories():
        return ['leetcode', 'lintcode']

    @staticmethod
    @lru_cache()
    def list(file_path):
        mod_datetime = datetime.fromtimestamp(os.path.getmtime(file_path))
        res = set()
        format_lines = []
        current_number = 0
        dup = set()
        with open(file_path, 'r') as file:
            for line in file.readlines():
                format_lines.append(f'{line}')
                match = re.match(r'^([\d\+\-]+)\.?\s([^\s]+)', line)
                if match is None:
                    continue
                
                current_number += 1
                mark = match.group(1)
                link = match.group(2)
                parsed_link = urlparse(link)

                match = re.search(r'\/problems?\/([^\/]+)\/?', parsed_link.path)
                if not match:
                    continue

                name = match.group(1)
                match = re.search(r'(www\.)?(\w+)\.com', parsed_link.netloc)
                source = match.group(2)
                
                s = Problem(link, source, mark, name, '', mod_datetime)

                if mark.isnumeric():
                    format_lines[-1] = f'{current_number}. {s.link}\n'
                else:
                    format_lines[-1] = f'- {s.link}\n'


                if s in res:
                    dup.add(s.name)
                    format_lines[-1] = f'{format_lines[-1].strip()} +duplicate \n'
                else:
                    res.add(s)
        
        with open(file_path, 'w') as file:
            file.writelines(format_lines)

        return res, dup, current_number

    @staticmethod
    @lru_cache()
    def all() -> dict:
        all_solutions = collections.defaultdict(list)
        for source in Problem.directories():
            for file_name in os.listdir(source):
                if file_name == '.DS_Store':
                    continue

                path = os.path.join(f'./{source}/{file_name}')
                name, extension = os.path.splitext(file_name)
                number, name = name.split('.')
                mod_datetime = datetime.fromtimestamp(os.path.getmtime(path))

                s = Problem(path, source, number, name, extension, mod_datetime)
                if extension in EXTENSION:
                    with open(path, 'r') as code:
                        texts = code.read().split('\n')[:5]
                        text = '\n'.join(texts)
                        tag_match = re.search(r"Tag: (.+)", text)
                        time_match = re.search(r"Time: (.+)", text)
                        space_match = re.search(r"Space: (.+)", text)
                        link_match = re.search(r"Ref: (.+)", text)
                        note_match = re.search(r"Note: (.+)", text)
     
                        s.tags = tag_match.group(1) if tag_match else '-'
                        s.time = Markdown.escape(time_match.group(1) if time_match else '-')
                        s.space = Markdown.escape(space_match.group(1) if space_match else '-')
                        s.ref = link_match.group(1) if link_match else '-'                
                        s.note = Markdown.escape(note_match.group(1) if note_match else '-')

                all_solutions[s.link].append(s)

        return all_solutions

    @staticmethod
    def statistic() -> int:
        all_solutions = Problem.all()
        source_dict = collections.defaultdict(int)
        count = 0

        duplicates = []
        for k, v in all_solutions.items():
            if len(set(v)) > 1:
                duplicates.append(f"- **\"{k}\"** ({', '.join([s.source for s in set(v)])})")
                Logger.log(f"{k} {v}", Logger.WARNING)

            solutions = [s for s in v if s.extension in EXTENSION]
            if len(solutions) > 0:
                s1 = solutions[0]
                source_dict[s1.source] += 1
                if getattr(s1, 'time') != 'N/A' and getattr(s1, 'space') != 'N/A': 
                    count += 1

                attributes = ['tags', 'time', 'space', 'note', 'ref']
                for i in range(1, len(solutions)):
                    source_dict[s1.source] += 1
                    s2 = solutions[i]
                    for attr in attributes:
                        if getattr(s1, attr) != getattr(s2, attr):
                            Logger.log(f'[Inconsistency]', Logger.WARNING, end=' ')
                            Logger.log(f'{s1.extension} vs. {s2.extension}', end=' ')
                            Logger.log(f'"{getattr(s1, attr)}" != "{getattr(s2, attr)}"', Logger.WARNING, end=' ')
                            Logger.log(f'{attr}', Logger.OKBLUE, end=' ')
                            Logger.log(f'{s1} {s2}', Logger.OKGREEN)

        Logger.log('----solutions----', Logger.BOLD)
        for k, v in source_dict.items():
            Logger.log(f'{k} files = {v}')
        Logger.log(f'solved = {count}', Logger.OKCYAN)

        res = []
        if len(duplicates) > 0:
            res.append("**Duplicates:**")
            res += duplicates
        
        res.append(f"**Solved**: {count} problems")
        return res

    def __init__(self, path, source, number, name, extension, modify_date) -> None:
        self.path = path
        self.source = source
        self.number = number
        self.name = name
        self.extension = extension
        self.update = modify_date
        self.tags = '-'
        self.time = '-'
        self.space = '-'
        self.note = '-'
        self.ref = '-'

    @property
    def title(self) -> str:
        roman_rex = re.compile(r"(?:(?<=\W)|^)M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$", re.IGNORECASE)
        problem = self.name.replace('-', ' ')
        orginal_title = f'{problem}'.title()
        return re.sub(roman_rex, lambda x: x.group(0).upper(), orginal_title)

    @property
    def link_title(self) -> str:
        return f'{self.source}-{self.number}'.title()

    @property
    def link(self) -> str:
        if self.source.lower() == 'leetcode':
            return f'https://leetcode.com/problems/{self.name}/'
        if self.source.lower() == 'lintcode':
            return f'https://www.lintcode.com/problem/{self.name}/'
        else:
            return '#'
        
    @property
    def language(self) -> str:
        return EXTENSION.get(self.extension, self.extension.strip('.'))

    def __eq__(self, other):
        return isinstance(other, Problem) and self.link == other.link

    def __hash__(self):
        return hash(self.link)

    def __repr__(self) -> str:
        return self.path

    def __str__(self) -> str:
        return self.__repr__()

if __name__ == "__main__":
    with open("README.md", "w") as f:
        
        Markdown.title1(f, "算法/Algorithm")
        Markdown.paragraph(f, [
            "LeetCode解题报告，记录自己的leetcode成长之路", 
            "LeetCode solutions, written in python and cpp"])

        Markdown.title2(f, "链接/Links")
        Markdown.bullet(f, [
            Markdown.link('本人博客', 'https://blog.mogoal.com/category/#Algorithm'),
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

        Markdown.title2(f, "书籍/Books")
        Markdown.bullet(f, [
            "《算法技术手册》/ Algorithms in a Nutshell",
            "《STL源码剖析》/ The Annotated STL Sources",
            "《算法心得：高效算法的奥秘》/ Hacker's Delight, 2nd Edition",
            "《数学之美》(A chinese version book by Doctor Wujun)",
            "《编程之美 : 微软技术面试心得》(A chinese version book by Mircosoft Developers)"
            ""
        ])

        Markdown.title2(f, "列表/List")
        Markdown.list_table(f)
        Markdown.paragraph(f, Problem.statistic())

        Markdown.title2(f, "类型/Category")
        Markdown.bullet(f, [Markdown.tag(c) for c in SHOW_CATEGORIES])
        Markdown.solution_table(f, ALL_CATEGORIES)