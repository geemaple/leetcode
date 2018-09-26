class TrieNode(object):
    def __init__(self, *args, **kwargs):
        self.children = {}
        self.is_word = False
        self.words = []

class Trie(object):
    def __init__(self, *args, **kwargs):
        self.root = TrieNode()

    def addWord(self, word):
        cur = self.root
        for c in word:

            cur.words.append(word)
            if c not in cur.children:
                cur.children[c] = TrieNode()
            
            cur = cur.children[c]

        cur.is_word = True

    def prefixWords(self, prefix):
        cur = self.root
        for c in prefix:
            if c not in cur.children:
                return []
            cur = cur.children[c]

        return cur.words 

class Solution(object):
    def __init__(self, *args, **kwargs):
        self.trie = Trie()

    def buildTrie(self, words):
        for w in words:
            self.trie.addWord(w)

    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """

        res = []
        ans = []
        self.buildTrie(words)
        self.dfs(words, ans, res)

        return res

    def dfs(self, words, ans, res):
        if len(ans) == len(words[0]):
            res.append(ans[:])
            return

        prefix = ''
        size = len(ans)
        for i in range(size):
            prefix += ans[i][size]

        candidates = self.trie.prefixWords(prefix)

        for i in range(len(candidates)):

            ans.append(candidates[i])
            self.dfs(words, ans, res)
            ans.pop()
