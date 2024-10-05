
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


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





s = Solution()
a = [["X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X","X"],["X","X","X","X","X","X","X","X","X","O","O","O","X","X","X","X","X","X","X","X"],["X","X","X","X","X","O","O","O","X","O","X","O","X","X","X","X","X","X","X","X"],["X","X","X","X","X","O","X","O","X","O","X","O","O","O","X","X","X","X","X","X"],["X","X","X","X","X","O","X","O","O","O","X","X","X","X","X","X","X","X","X","X"],["X","X","X","X","X","O","X","X","X","X","X","X","X","X","X","X","X","X","X","X"]]
ts = datetime.now()
res = s.solve(a)
print(datetime.now() - ts)
print('\n'.join([str(x) for x in a]))
