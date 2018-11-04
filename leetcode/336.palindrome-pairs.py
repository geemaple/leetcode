class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.candidates = []
        self.index = -1

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def add_word(self, word, index):
        cur = self.root

        for i in range(len(word) - 1, -1, -1):
            c = word[i]
            if c not in cur.children:
                cur.children[c] = TrieNode()

            if self.is_palindrome(word, 0, i):
                cur.candidates.append(index)

            cur = cur.children[c]

        cur.candidates.append(index)
        cur.index = index

    def search(self, words, i, res):
        word = words[i]
        cur = self.root
   
        for j in range(len(word)):
            if cur.index != i and cur.index >= 0 and self.is_palindrome(word, j , len(word) - 1):
                res.append([i, cur.index])

            if word[j] not in cur.children:
                return None

            cur = cur.children[word[j]]

        for j in cur.candidates:
            if i == j:
                continue

            res.append([i, j])

    def find_posfix(self, postfix):
        cur = self.root
        for c in postfix:
            if c not in cur.children:
                return None
            cur = cur.children[c]
        return cur

    def is_palindrome(self, word, start, end):
        while (start < end):
            if word[start] != word[end]:
                return False
            start += 1
            end -= 1
            
        return True

class Solution(object):
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        trie = Trie()
        
        for i in range(len(words)):
            trie.add_word(words[i], i)

        res = []
        for i in range(len(words)):
            trie.search(words, i, res)

        return res