from typing import List
import collections
class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        m = len(board)
        n = len(board[0])

        for i in range(m):
            for j in range(n):
                if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                    self.dfs(board, i, j)

        for i in range(m):
            for j in range(n):
                if board[i][j] == '0':
                    board[i][j] = 'X'

    def dfs(self, board: List[List[str]], i: int, j: int):

        if board[i][j] != 'O':
            return

        directions = [-1, 0, 1, 0, -1]
        stack = [(i, j)]
        while len(stack) > 0:
            x, y = stack.pop()
            board[x][y] = 'T'
            print(x, y)

            for k in range(4):
                dx = x + directions[k]
                dy = y + directions[k + 1]

                if 0 <= dx < len(board) and 0 <= dy < len(board[dx]) and board[dx][dy] == 'O':
                    stack.append((dx, dy))


s = Solution()
t = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
s.solve(t)
print(t)