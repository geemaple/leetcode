#  Tag: Depth First Search/DFS, Trie
#  Time: O(N * P^5)
#  Space: O(N)
#  Ref: Leetcode-425
#  Note: -

#  Given a set of words **without duplicates**, find all [`word squares`](https://en.wikipedia.org/wiki/Word_square "Word square") you can build from them.
#  
#  A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
#  
#  For example, the word sequence `["ball","area","lead","lady"]` forms a word square because each word reads the same both horizontally and vertically.
#  ```
#  b a l l
#  a r e a
#  l e a d
#  l a d y
#  ```
#  
#  **Example 1:**
#  ```
#  Input:
#  ["area","lead","wall","lady","ball"]
#  Output:
#  [["wall","area","lead","lady"],["ball","area","lead","lady"]]
#  
#  Explanation:
#  The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
#  ```
#  
#  **Example 2:**
#  ```
#  Input:
#  ["abat","baba","atan","atal"]
#  Output:
#   [["baba","abat","baba","atan"],["baba","abat","baba","atal"]]
#  ```
#  
#  - There are at least 1 and at most 1000 words.
#  - All words will have the exact same length.
#  - Word length is at least 1 and at most 5.
#  - Each word contains only lowercase English alphabet `a-z`.

from typing import (
    List,
)

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.prefix = []

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add(self, word:str):
        cur = self.root
        for x in word:
            if x not in cur.children:
                cur.children[x] = TrieNode()
            cur = cur.children[x]
            cur.prefix.append(word)
        cur.is_word = True

    def prefix(self, word: str) -> list:
        cur = self.root
        for x in word:
            if x not in cur.children:
                return []
            cur = cur.children[x]
        return cur.prefix

class Solution:
    """
    @param words: a set of words without duplicates
    @return: all word squares
             we will sort your return value in output
    """
    def word_squares(self, words: List[str]) -> List[List[str]]:
        # write your code here
        n = len(words)
        k = len(words[0])
        tree = Trie()
        for word in words:
            tree.add(word)

        res = []
        for i in range(n):
            self.helper(k, tree, [words[i]], res)
        return res
        
    def helper(self, k: int, tree: Trie, ans: list, res: list):
        if len(ans) == k:
            res.append(list(ans))
            return
        index = len(ans)
        pre = ''.join([x[index] for x in ans])
        for word in tree.prefix(pre):
            self.helper(k, tree, ans + [word], res)

class TireNode:
    def __init__(self):
        self.is_word = False
        self.children = {}
        self.word = None

class Trie:
    def __init__(self):
        self.root = TireNode()

    def add(self, word):
        cur = self.root
        
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TireNode()
            cur = cur.children[ch]
            
        cur.is_word = True
        cur.word = word

    def prefix(self, word) -> list:
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                return []
            cur = cur.children[ch]

        res = []
        self.dfs(cur, res)
        return res

    def dfs(self, cur, res):
        if cur.is_word:
            res.append(cur.word)

        for ch, neighbor in cur.children.items():
            self.dfs(neighbor, res)

class Solution:
    """
    @param words: a set of words without duplicates
    @return: all word squares
             we will sort your return value in output
    """
    def word_squares(self, words: List[str]) -> List[List[str]]:
        # write your code here
        k = len(words[0])
        trie = Trie()
        for x in words:
            trie.add(x)
        res = []
        self.helper(k, trie, [], res)
        return res

    def helper(self, k: int, trie: Trie, ans: list, res: list):
        if len(ans) == k:
            res.append(ans)
            return
        
        index = len(ans)
        prefix = ''.join(x[index] for x in ans)
        for word in trie.prefix(prefix):
            self.helper(k, trie, ans + [word], res)