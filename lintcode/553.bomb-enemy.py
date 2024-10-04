#  Tag: Array, Simulation
#  Time: O(NM)
#  Space: O(NM)
#  Ref: Leetcode-361
#  Note: -

#  Given a 2D grid, each cell is either a wall `'W'`, an enemy `'E'` or empty `'0'` (the number zero), return the maximum enemies you can kill using one bomb.
#  The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
#  
#  **Example1**
#  
#  ```
#  Input:
#  grid =[
#       "0E00",
#       "E0WE",
#       "0E00"
#  ]
#  Output: 3
#  Explanation:
#  Placing a bomb at (1,1) kills 3 enemies
#  ```
#  
#  **Example2**
#  
#  ```
#  Input:
#  grid =[
#       "0E00",
#       "EEWE",
#       "0E00"
#  ]
#  Output: 2
#  Explanation:
#  Placing a bomb at (0,0) or (0,3) or (2,0) or (2,3) kills 2 enemies
#  ```
#  
#  You can only put the bomb at an empty cell.

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

        if len(grid) == 0:
            return 0

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
                if grid[i][j] == '0':
                    res = max(res, up[i][j] + left[i][j] + bottom[i][j] + right[i][j])

        return res