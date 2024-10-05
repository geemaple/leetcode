#  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
#  Time: O(MN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
#  
#  Connect: A cell is connected to adjacent cells horizontally or vertically.
#  Region: To form a region connect every 'O' cell.
#  Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
#  
#  A surrounded region is captured by replacing all 'O's with 'X's in the input matrix board.
#   
#  Example 1:
#  
#  Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
#  Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
#  Explanation:
#  
#  In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.
#  
#  Example 2:
#  
#  Input: board = [["X"]]
#  Output: [["X"]]
#  
#   
#  Constraints:
#  
#  m == board.length
#  n == board[i].length
#  1 <= m, n <= 200
#  board[i][j] is 'X' or 'O'.
#  
#  

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        for i in range(m):
            self.dfs(board, i, 0)
            self.dfs(board, i, n - 1)

        for j in range(n):
            self.dfs(board, 0, j)
            self.dfs(board, m - 1, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                elif board[i][j] == 'T':
                    board[i][j] = 'O'
         
    def dfs(self, board: List[List[str]], i: int, j: int):

        if board[i][j] != 'O':
            return

        directions = [-1, 0, 1, 0, -1]
        stack = [(i, j)]
        while len(stack) > 0:
            x, y = stack.pop()
            board[x][y] = 'T'

            for k in range(4):
                dx = x + directions[k]
                dy = y + directions[k + 1]

                if 0 <= dx < len(board) and 0 <= dy < len(board[dx]) and board[dx][dy] == 'O':
                    stack.append((dx, dy))


class UionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.sea = [False for i in range(n)]

    def find(self, a) -> int:
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.table[root_a] = root_b
            if self.sea[root_a]:
                self.sea[root_b] = True

class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        n = len(board)
        m = len(board[0])

        directions = [-1, 0, 1, 0, -1]
        uf = UionFind(n * m)

        for i in range(n):
            uf.sea[i * m + 0] = True
            uf.sea[i * m + m - 1] = True

        for j in range(m):
            uf.sea[0 * m + j] = True
            uf.sea[(n - 1) * m + j] = True


        for i in range(n):
            for j in range(m):
                if board[i][j] == 'X':
                    continue

                for d in range(4):
                    x = i + directions[d]
                    y = j + directions[d + 1]
                    if 0 <= x < n and 0 <= y < m and board[x][y] != 'X':
                        uf.connect(i * m + j, x * m + y)

        for i in range(n):
            for j in range(m):
                if board[i][j] == 'X':
                    continue

                root = uf.find(i * m + j)
                if not uf.sea[root]:
                    board[i][j] = 'X'