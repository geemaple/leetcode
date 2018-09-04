class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.word = None

class Trie(object):
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root

        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]

        node.is_word = True
        node.word = word

    def search(self, node, c):
        if c not in node.children:
            return None
        return node.children[c]

class Solution(object):

    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    def findWords(self, board, words):
        """
        :type board: List[List[str]]
        :type words: List[str]
        :rtype: List[str]
        """
        visted = set()
        res = []
        trie = Trie()

        for word in words:
            trie.insert(word)

        for i in range(len(board)):
            for j in range(len(board[i])):
                self.search_dfs(board, i, j, visted, trie, trie.root, res)

        return res

        
    def check_in_board(self, board, x, y):
        return (0 <= x < len(board) and 0 <= y < len(board[x]))

    def search_dfs(self, board, x, y, visted, trie, node, res):

        node = trie.search(node, board[x][y])

        if node is None:
            return

        if node.is_word:
            node.is_word = False
            res.append(node.word)

        visted.add((x,y))

        for direction in self.directions:
            new_x = x + direction[0]
            new_y = y + direction[1]

            if self.check_in_board(board, new_x, new_y) and (new_x, new_y) not in visted:
                self.search_dfs(board, new_x, new_y, visted, trie, node, res)

        visted.remove((x, y))