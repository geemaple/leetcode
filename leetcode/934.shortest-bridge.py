#  Tag: Array, Depth-First Search, Breadth-First Search, Matrix
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  You are given an n x n binary matrix grid where 1 represents land and 0 represents water.
#  An island is a 4-directionally connected group of 1's not connected to any other 1's. There are exactly two islands in grid.
#  You may change 0's to 1's to connect the two islands to form one island.
#  Return the smallest number of 0's you must flip to connect the two islands.
#   
#  Example 1:
#  
#  Input: grid = [[0,1],[1,0]]
#  Output: 1
#  
#  Example 2:
#  
#  Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
#  Output: 2
#  
#  Example 3:
#  
#  Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
#  Output: 1
#  
#   
#  Constraints:
#  
#  n == grid.length == grid[i].length
#  2 <= n <= 100
#  grid[i][j] is either 0 or 1.
#  There are exactly two islands in grid.
#  
#  

import collections
class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        n = len(grid)
        directions = [-1, 0, 1, 0, -1]
        points = self.findIsland(grid)
        q = collections.deque(points)
        res = 0

        while len(q) > 0:
            res += 1            
            level = len(q)
            for _ in range(level):
                x, y = q.popleft()
                for k in range(4):
                    dx = x + directions[k]
                    dy = y + directions[k + 1]
                    if 0 <= dx < n and 0 <= dy < n:
                        if grid[dx][dy] == 0:
                            q.append((dx, dy))
                            grid[dx][dy] = 2
                        elif grid[dx][dy] == 1:
                            return res
            
        return -1

    def findIsland(self, grid: List[List[int]]) -> list:
        n = len(grid)
        directions = [-1, 0, 1, 0, -1]
        points = []
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 1:
                    stack = [(i, j)]
                    visited = set()

                    while len(stack) > 0:
                        x, y = stack.pop()
                        visited.add((x, y))
                        grid[x][y] = 2
                        
                        for k in range(4):
                            dx = x + directions[k]
                            dy = y + directions[k + 1]
                            if 0 <= dx < n and 0 <= dy < n and (dx, dy) not in visited:
                                if grid[dx][dy] == 0:
                                    points.append((dx, dy))
                                elif grid[dx][dy] == 1:
                                    stack.append((dx, dy))
                                
                    return points