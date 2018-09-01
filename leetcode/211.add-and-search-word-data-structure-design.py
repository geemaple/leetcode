class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.is_word = False

class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()
        

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: void
        """
        node = self.root
        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]
        node.is_word = True
        

    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        return self.search_dfs(self.root, word, 0)

    def search_dfs(self, node, word, index):
        
        if node is None:
            return False

        if index >= len(word):
            return node.is_word

        c = word[index]
        if c != '.':
            return self.search_dfs(node.children.get(c, None), word, index + 1)
        else:
            for k, v in node.children.iteritems():
                if (self.search_dfs(v, word, index + 1)):
                    return True

        return False


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
