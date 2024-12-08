# Category: - 
# Time: -
# Space: -
# Ref: -

from urllib.parse import urlparse
import requests
from bs4 import BeautifulSoup
from collections import defaultdict
import json
import os
import argparse
import re
import sys
from logger import Logger

COMMENT = {
    'python3': '#',
    'python': '#',
    'cpp': '//',
    'java': '//',
    'Pandas': '#',
    'MySQL': '--',

}

EXTENTION = {
    'python3': 'py',
    'python': 'py',
    'cpp': 'cpp',
    'java': 'java',
    'Pandas': 'py',
    'MySQL': 'sql',
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
        self.paid = False

    @property
    def question_name(self) -> str:
        return '-'.join(self.title.lower().split())

    @property
    def file_name(self) -> str:
        extension = 'vip' if self.paid else EXTENTION[self.lang]
        return f'{self.number}.{self.question_name}.{extension}'

    def write_comments(self, f, content):
        for c in content:
            f.write(f'{COMMENT[self.lang]}  {c}\n')

        f.write(f'\n')

    def write_code(self, f, content):
        f.write(content)

    def write(self, overwrite) -> None:
        path = os.path.join(f'./{self.source}', self.file_name)
        if self.paid:
            Logger.log(f"[Error] paid question not supported", Logger.FAIL)
            with open(path, 'w') as file:
                pass
        else:
            Logger.log(f'{path}', Logger.OKBLUE)
            if overwrite or not os.path.exists(path):
                with open(path, 'w') as file:
                    self.write_comments(file, [
                        f'Tag: {", ".join(self.tags)}',
                        f'Time: -',
                        f'Space: -',
                        f'Ref: -',
                        f'Note: -',
                        ])
                    self.write_comments(file, self.content.split('\n'))
                    self.write_code(file, self.editorData)
                    Logger.log(f'[OK] download success', Logger.OKGREEN)
            else:
                raise Exception('already exists. But you can use -f/--force option to overwrite')

    def debug_description(self):
        Logger.log(f"quetionn {self.number} {self.title if len(self.title) > 0 else ''}", Logger.OKGREEN)

def parse_leetcode(url, lang, translate):
    session = requests.session()

    problem = Problem('leetcode', lang)
    problem.title = re.search(r"/problems/([\w-]+)/?", url).group(1)
    
    graphql = urlparse(url)._replace(path="/graphql/").geturl()
    headers = {
        'Referer': url,
    }

    question_title = {
            "query":"\n    query questionTitle($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    title\n    titleSlug\n    isPaidOnly\n    difficulty\n    likes\n    dislikes\n    categoryTitle\n  }\n}\n    ",
            "variables":{
                    "titleSlug": problem.question_name
                },
            "operationName":"questionTitle"
        }
    
    response = session.post(graphql, headers=headers, json=question_title)
    data = response.json()
    problem.number = data["data"]["question"]["questionFrontendId"]
    problem.paid = bool(data["data"]["question"]["isPaidOnly"])
    if problem.paid:
        return problem

    question_topic = {
                "query":"\n    query singleQuestionTopicTags($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    topicTags {\n      name\n      slug\n    }\n  }\n}\n    ",
                "variables": {
                        "titleSlug": problem.question_name
                    },
                "operationName":"singleQuestionTopicTags"
            }
    response = session.post(graphql, headers=headers, json=question_topic)
    data = response.json()
    problem.tags =  [tag['name'] for tag in data['data']['question']['topicTags']]

    question_content = {
            "query": "\n    query questionContent($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    content\n    mysqlSchemas\n    dataSchemas\n  }\n}\n    ",
            "variables": {
                    "titleSlug": problem.question_name
                },
            "operationName":"questionContent"
        }
    response = session.post(graphql, headers=headers, json=question_content)
    data = response.json()
    soup = BeautifulSoup(str(data["data"]["question"]["content"]), 'html.parser')
    problem.content = soup.text

    question_editor = {
        'query': '\n    query questionEditorData($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    questionId\n    questionFrontendId\n    codeSnippets {\n      lang\n      langSlug\n      code\n    }\n    envInfo\n    enableRunCode\n    hasFrontendPreview\n    frontendPreviews\n  }\n}\n    ',
        'variables': {
            'titleSlug': problem.question_name
        },
        'operationName': 'questionEditorData',
    }

    response = session.post(graphql, headers=headers, json=question_editor)
    state = response.json()
    editorData = state['data']['question']['codeSnippets'] or []
    for code in editorData:
        if code['langSlug'].lower() == lang.lower():
            problem.editorData = code['code']
            break
    else:
        problem.editorData = editorData[0]['code']
        problem.lang = editorData[0]['lang']

    if translate:
        question_translattion = {
                "query":"\n    query questionTranslations($titleSlug: String!) {\n  question(titleSlug: $titleSlug) {\n    translatedTitle\n    translatedContent\n  }\n}\n    ",
                "variables": {
                        "titleSlug": problem.question_name
                    },
                "operationName":"questionTranslations"
            }

        response = session.post(graphql, headers=headers, json=question_translattion)
        data = response.json()
        soup = BeautifulSoup(str(data["data"]["question"]["translatedContent"]), 'html.parser')
        problem.content = soup.text
    
    return problem

def parse_lintcode(url, lang, translate):

    redirect = requests.get(url)
    url = redirect.url

    numbers = re.findall(r'\d+', url)
    if len(numbers) == 0:
        return
        
    number = numbers[0]
    url = f'https://c1.lintcode.com/v2/api/problems/{number}/?lang={1 if translate else 2}'
    response = requests.get(url)

    problem = Problem('lintcode', lang)
    problem.number = number

    query = json.loads(response.text)
    if not query['success']:
        vip_url = f'https://apiv1.lintcode.com/new/api/check-vip/problems/{number}/?lang={1 if translate else 2}'
        response = requests.get(vip_url)
        query = json.loads(response.text)
        data = query['data'] if isinstance(query['data'], dict) else defaultdict(str)
        problem.title = re.sub(r'[()]', '', data['problem_info']['title'])
        problem.paid = True
        return problem
    
    data = query['data'] if isinstance(query['data'], dict) else defaultdict(str)
    problem.title = data['unique_name']

    description = data['description'].replace('. ', '.\n')
    example = data['example'] 
    notice = data["new_notice"] if data["new_notice"] is not None else data['notice']

    problem.content = f'{description}\n\n{example}\n\n{notice}'

    tags = data['tags']
    problem.tags = [t["name"] for t in tags]

    problem.companies = data['company_tags']

    url = f'https://apiv1.lintcode.com/new/api/problems/{number}/reset/?scene=1&language={lang}'
    response = requests.get(url)
    query = json.loads(response.text)
    data = query['data'] if isinstance(query['data'], dict) else defaultdict(str)
    problem.editorData = data['code']

    return problem

class Parser(argparse.ArgumentParser):
    def error(self, message):
        sys.stderr.write('error: %s\n' % message)
        self.print_help()
        sys.stderr.write('\n例如(e.g.):\n')
        sys.stderr.write('python problem.py https://leetcode.com/problems/online-stock-span/ -l python')
        sys.exit(2)

if __name__ == '__main__':
    parser = Parser("problem")
    parser.add_argument("url", help="leetcode/lintcode url", type=str)
    parser.add_argument("-l", "--lang", help="coding language: python(default), cpp or java", required=False, type=str, default='python3')
    parser.add_argument("-f", "--force", help="overwrite existing files", required=False, action='store_true')
    parser.add_argument("-t", "--translate", help="get transtaled version content", required=False, action='store_true')
    args = parser.parse_args()

    problem = None
    if 'leetcode' in args.url:
        problem = parse_leetcode(args.url, args.lang, args.translate)
    elif 'lintcode' in args.url:
        problem = parse_lintcode(args.url, args.lang, args.translate)
    else:
        parser.print_help()
    
    if problem is not None:
        problem.debug_description()

        try:
            problem.write(args.force)
        except Exception as e:
            Logger.log(f'[Warning]{str(e)}', Logger.WARNING)


