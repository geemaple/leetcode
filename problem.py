# Category: - 
# Time: -
# Space: -
# Ref: -

import requests
from bs4 import BeautifulSoup
import json
import os
import argparse
import re

COMMENT = {
    'python': '# ',
    'cpp': '// ',
    'java': '// '
}

EXTENTION = {
    'python': 'py',
    'cpp': 'cpp',
    'java': 'java'
}

lintcode_lang_params = {
    'python': 'python3',
    'cpp': 'cpp',
    'java': 'java'
}

class Problem:
    def __init__(self, source, lang) -> None:
        self.source = source
        self.number = 0
        self.title = ''
        self.content = ''
        self.tags = ''
        self.stats = ''
        self.editorData = ''
        self.lang = lang
        self.companies = ''

    @property
    def file_name(self) -> str:
        hyphen_title = '-'.join(self.title.lower().split())
        return f'{self.number}.{hyphen_title}.{EXTENTION[lang]}'

    def write_comments(self, f, content):
        for c in content:
            f.write(f'{COMMENT[self.lang]} {c}\n')

        f.write(f'\n')

    def write_code(self, f, content):
        f.write(content)

    def write(self, file) -> None:
        self.write_comments(file, [
            f'Category: {", ".join(self.tags)}',
            f'Time: -',
            f'Space: -',
            f'Ref: -'
            ])
        self.write_comments(file, self.content.split('\n'))
        self.write_code(file, self.editorData)

def parse_leetcode(text, lang):
    soup = BeautifulSoup(text, 'html.parser')

    problem = soup.find('script', type='application/json')

    json_text = problem.contents[0] 

    query = json.loads(json_text)['props']['pageProps']['dehydratedState']['queries']

    problem = Problem('leetcode', lang)

    for data in query:
        
        # print('\n', data['queryKey'])
        if 'questionTitle' in data['queryKey']:
            problem.number = data['state']['data']['question']['questionFrontendId']
            problem.title = data['state']['data']['question']['title']
            
        elif 'questionContent' in data['queryKey']:
            content = BeautifulSoup(data['state']['data']['question']['content'], 'html.parser')
            problem.content = content.text
            
        elif 'singleQuestionTopicTags' in data['queryKey']:
          problem.tags = [tag['name'] for tag in data['state']['data']['question']['topicTags']]

        elif 'questionEditorData' in data['queryKey']:
            editorData = data['state']['data']['question']['codeSnippets']
            for code in editorData:
                if code['langSlug'].lower() == lang.lower():
                    problem.editorData = code['code']
        elif 'questionInterviewOptions' in data['queryKey']:
            companies = data['state']['data']['interviewed']['companies']
            problem.companies = [c['name'] for c in companies]
        # else:
            # print(data['state']['data'])

    return problem

def parse_lintcode(number, lang):

    url = f'https://c1.lintcode.com/v2/api/problems/{numbers[0]}/?lang=2'
    response = requests.get(url)

    query = json.loads(response.text)
    data = query['data']
    problem = Problem('lintcode', lang)

    problem.number = number
    problem.title = data['title']

    description = data['description']
    example = data['example']
    notice = data["new_notice"] if data["new_notice"] is not None else data['notice']

    problem.content = f'{description}\n{example}\n{notice}'

    tags = data['tags']
    problem.tags = [t["name"] for t in tags]

    problem.companies = data['company_tags']

    url = f'https://apiv1.lintcode.com/new/api/problems/{number}/reset/?scene=1&language={lintcode_lang_params[lang]}'
    response = requests.get(url)
    query = json.loads(response.text)
    data = query['data']
    problem.editorData = data['code']

    return problem


if __name__ == '__main__':
    parser = argparse.ArgumentParser("coder")
    parser.add_argument("url", help="leetcode/lintcode url", type=str)
    parser.add_argument("-l", "--lang", help="coding language python or cpp", required=False, type=str, default='python')
    args = parser.parse_args()
    url, lang = args.url, args.lang

    problem = None
    if 'leetcode' in url:
        response = requests.get(url.replace('cn', 'com'))
        problem = parse_leetcode(response.text, lang)
    elif 'lintcode' in url:
        numbers = re.findall(r'\d+', url)
        if len(numbers) > 0:
            problem = parse_lintcode(numbers[0], lang)
    else:
        exit(1)  
    
    if problem is not None:
        path = os.path.join(f'./{problem.source}', problem.file_name)
        if not os.path.exists(path):
            with open(path, 'w') as f:
                problem.write(f)
        else:
            print(f'{path} already exist')
