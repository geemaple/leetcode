#  Tag: Array, Breadth-First Search, Matrix
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -

#  You are given an m x n grid where each cell can have one of three values:
#  
#  0 representing an empty cell,
#  1 representing a fresh orange, or
#  2 representing a rotten orange.
#  
#  Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
#  Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
#   
#  Example 1:
#  
#  
#  Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
#  Output: 4
#  
#  Example 2:
#  
#  Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
#  Output: -1
#  Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
#  
#  Example 3:
#  
#  Input: grid = [[0,2]]
#  Output: 0
#  Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 10
#  grid[i][j] is 0, 1, or 2.
#  
#  

from collections import deque
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        q = deque()
        fresh = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    fresh += 1
                elif grid[i][j] == 2:
                    q.append((i, j))

        if fresh == 0:
            return 0

        directions = [-1, 0, 1, 0, -1]
        res = 0
        while len(q) > 0:
            size = len(q)
            res += 1
            for _ in range(size):
                i, j = q.popleft()
                for d in range(4):
                    x = i + directions[d]
                    y = j + directions[d + 1]
                    if 0 <= x < n and 0 <= y < m and grid[x][y] == 1:
                        fresh -= 1
                        grid[x][y] = 2
                        q.append((x, y))

        return res - 1 if fresh == 0 else -1