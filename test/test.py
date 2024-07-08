from typing import List
import collections
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:

        node_distance = {}
        for w in wordList:
            node_distance[w] = 0

        if endWord not in node_distance:
            return []

        self.bfs(endWord, node_distance)
        
        res = []
        self.dfs(node_distance, endWord, {beginWord}, [beginWord], res)
            
        return res
        
    def dfs(self, node_distance: dict, endWord: str, visited:set, tmp: List[str], res: List[List[str]]):
        word = tmp[-1]
        if word == endWord:
            res.append(tmp.copy())
            return
        
        distance = node_distance.get(word, float('inf'))
        for n in self.get_next(word, visited, node_distance):
            if node_distance[n] >= distance:
                continue

            visited.add(n)
            self.dfs(node_distance, endWord, visited, tmp + [n], res)
            visited.remove(n)


    def bfs(self, endWord: str, node_distance: dict):
        distance = 0
        q = collections.deque([endWord])
        visited = {endWord}

        while len(q) > 0:
            c = len(q)
            for _ in range(c):
                word = q.popleft()
                node_distance[word] = distance

                for n in self.get_next(word, visited, node_distance):
                    visited.add(n)
                    q.append(n)

            distance += 1

    def get_next(self, word: str, visited: set, node_distance: dict) -> List:
        res = []
        for i in range(len(word)):
            for l in 'abcdefghijklmnopqrstuvwxyz':
                if l == word[i]:
                    continue

                n = word[:i] + l + word[i + 1:]
                if n not in node_distance or n in visited:
                    continue

                res.append(n)

        return res

s = Solution()
t = ["hot","dot","dog","lot","log","cog"]
res = s.findLadders('hit', 'cog', t)
print(res)