#  Tag: Array, String, Backtracking, Matrix
#  Time: O(MN*4^L)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given an m x n grid of characters board and a string word, return true if word exists in the grid.
#  The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
#   
#  Example 1:
#  
#  
#  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
#  Output: true
#  
#  Example 3:
#  
#  
#  Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
#  Output: false
#  
#   
#  Constraints:
#  
#  m == board.length
#  n = board[i].length
#  1 <= m, n <= 6
#  1 <= word.length <= 15
#  board and word consists of only lowercase and uppercase English letters.
#  
#   
#  Follow up: Could you use search pruning to make your solution faster with a larger board?
#  

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        visited = set()
        for i in range(m):
            for j in range(n):
                if self.dfs(board, word, 0, i, j, visited):
                    return True
        return False


    def dfs(self, board: List[List[str]], word: str, pos: int, x:int, y:int, visited: set) -> bool:
        
        if board[x][y] != word[pos]:
            return False

        if pos == len(word) - 1:
            return True

        visited.add((x, y))
        directions = [-1, 0, 1, 0, -1]
        for i in range(4):
            dx = x + directions[i]
            dy = y + directions[i + 1]

            if 0 <= dx < len(board) and 0 <= dy < len(board[dx]) and (dx, dy) not in visited:
                if self.dfs(board, word, pos + 1, dx, dy, visited):
                    return True
        visited.remove((x, y))
        return False    