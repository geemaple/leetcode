#  Tag: Array, Dynamic Programming, Memoization, Matrix
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/aZ38GCRokuM

#  You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
#  A V-shaped diagonal segment is defined as:
#  
#  The segment starts with 1.
#  The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
#  The segment:
#  	
#  Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
#  Continues the sequence in the same diagonal direction.
#  Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
#  
#  
#  
#  
#  Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.
#   
#  Example 1:
#  
#  Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
#  Output: 5
#  Explanation:
#  
#  The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
#  
#  Example 2:
#  
#  Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
#  Output: 4
#  Explanation:
#  
#  The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).
#  
#  Example 3:
#  
#  Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]
#  Output: 5
#  Explanation:
#  
#  The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).
#  
#  Example 4:
#  
#  Input: grid = [[1]]
#  Output: 1
#  Explanation:
#  The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).
#  
#   
#  Constraints:
#  
#  n == grid.length
#  m == grid[i].length
#  1 <= n, m <= 500
#  grid[i][j] is either 0, 1 or 2.
#  
#  

from functools import cache
class Solution:
    def lenOfVDiagonal(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])
        directions = [(-1, 1), (1, 1), (1, -1), (-1, -1)]
        next_val = [2, 2, 0]

        @cache
        def search(i: int, j: int, val: int, d: int, turn: bool) -> int:
            if i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != val:
                return 0

            dx = i + directions[d][0]
            dy = j + directions[d][1]
            res = 1 + search(dx, dy, next_val[val], d, turn)
            if not turn:
                tx = i + directions[(d + 1) % 4][0]
                ty = j + directions[(d + 1) % 4][1]
                res = max(res, 1 + search(tx, ty, next_val[val], (d + 1) % 4, True))

            return res

        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    for k in range(4):
                        res = max(res, search(i, j, 1, k, False))

        return res  