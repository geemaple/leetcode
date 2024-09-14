
from typing import List
from collections import defaultdict
import heapq
from collections import deque
from typing import (
    List,
)

from typing import (
    List,
)

class Solution:
    """
    @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
    @return: an integer, the maximum enemies you can kill using one bomb
    """
    def max_killed_enemies(self, grid: List[List[str]]) -> int:
        # write your code here
        n = len(grid)
        m = len(grid[0])

        up = [[0] * m for i in range(n)]
        left = [[0] * m for i in range(n)]
        bottom = [[0] * m for i in range(n)]
        right = [[0] * m for i in range(n)]

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'W':
                    continue
                
                addition = 1 if grid[i][j] == 'E' else 0
                if i == 0:
                    up[i][j] = addition
                else:
                    up[i][j] = up[i - 1][j] + addition

                if j == 0:
                    left[i][j] = addition
                else:
                    left[i][j] = left[i][j - 1] + addition

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if grid[i][j] == 'W':
                    continue

                addition = 1 if grid[i][j] == 'E' else 0
                if i == n - 1:
                    bottom[i][j] = addition
                else:
                    bottom[i][j] = bottom[i + 1][j] + addition

                if j == m - 1:
                    right[i][j] = addition
                else:
                    right[i][j] = right[i][j + 1] + addition


        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 'E':
                    res = max(res, up[i][j] + left[i][j] + bottom[i][j] + right[i][j] - 3)
                
                elif grid[i][j] == '0':
                    res = max(res, up[i][j] + left[i][j] + bottom[i][j] + right[i][j])

        return res


s = Solution()
res = s.max_killed_enemies(["0E00","E0WE","0E00"])
print(res)