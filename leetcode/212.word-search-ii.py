#  Tag: Array, String, Backtracking, Trie, Matrix
#  Time: O(NM*4^L)
#  Space: O(MN + KL)
#  Ref: -
#  Note: -

#  Given an m x n board of characters and a list of strings words, return all words on the board.
#  Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
#   
#  Example 1:
#  
#  
#  Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
#  Output: ["eat","oath"]
#  
#  Example 2:
#  
#  
#  Input: board = [["a","b"],["c","d"]], words = ["abcb"]
#  Output: []
#  
#   
#  Constraints:
#  
#  m == board.length
#  n == board[i].length
#  1 <= m, n <= 12
#  board[i][j] is a lowercase English letter.
#  1 <= words.length <= 3 * 104
#  1 <= words[i].length <= 10
#  words[i] consists of lowercase English letters.
#  All the strings of words are unique.
#  
#  

class TrieNode:
    def __init__(self):
        self.is_word = False
        self.children = {}
        self.word = None

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def add(self, word: str):
        cur = self.root
        for ch in word:
            if ch not in cur.children:
                cur.children[ch] = TrieNode()
            cur = cur.children[ch]
        cur.is_word = True
        cur.word = word

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        trie = Trie()
        for word in words:
            trie.add(word)

        res = []
        for i in range(len(board)):
            for j in range(len(board[i])):
                self.helper(i, j, board, trie.root, res)

        return res

    def helper(self, i: int, j: int, board: list, node: TrieNode, res: list):
    
        if board[i][j] not in node.children:
            return

        directions = [-1, 0 ,1 , 0, -1]
        child = node.children[board[i][j]]

        if child.is_word:
            child.is_word = False
            res.append(child.word)

        val = board[i][j]
        board[i][j] = '#'
        for d in range(4):
            x = i + directions[d]
            y = j + directions[d + 1]
            if 0 <= x < len(board) and 0 <= y < len(board[x]) and board[x][y] != '#':
                self.helper(x, y, board, child, res)
        board[i][j] = val
                