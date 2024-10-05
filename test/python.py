
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.word = None

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add(self, word: str):
        cur = self.root
        for x in word:
            if x not in cur.children:
                cur.children[x] = TrieNode()
            cur = cur.children[x]
        cur.is_word = True
        cur.word = word

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        n = len(board)
        m = len(board[0])
        tree = Trie()
        for word in words:
            tree.add(word)

        res = []
        for i in range(n):
            for j in range(m):
                visited = {(i , j)}
                self.dfs(board, tree.root, res, visited, i, j)

        return res

    def dfs(self, board: list, node: TrieNode, res: list, visited: set, i: int, j: int):
        print(visited)
        if board[i][j] not in node.children:
            return

        cur = node.children[board[i][j]]
        if cur.is_word:
            cur.is_word = False
            res.append(cur.word)
        
        directions = [-1, 0, 1, 0, -1]
        for d in range(4):
            x = i + directions[d]
            y = j + directions[d + 1]
            if 0 <= x < len(board) and 0 <= y < len(board[x]) and (x, y) not in visited:
                visited.add((x, y))
                self.dfs(board, cur, res, visited, x, y)
                visited.remove((x, y))
                



s = Solution()
a = [["a","b","c","e"],["x","x","c","d"],["x","x","b","a"]]
ts = datetime.now()
res = s.findWords(a, ["abc","abcd"])
print(datetime.now() - ts)
print(res)
