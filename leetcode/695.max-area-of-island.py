#  Tag: Array, Depth-First Search, Breadth-First Search, Union Find, Matrix
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
#  The area of an island is the number of cells with a value 1 in the island.
#  Return the maximum area of an island in grid. If there is no island, return 0.
#   
#  Example 1:
#  
#  
#  Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
#  Output: 6
#  Explanation: The answer is not 11, because the island must be connected 4-directionally.
#  
#  Example 2:
#  
#  Input: grid = [[0,0,0,0,0,0,0,0]]
#  Output: 0
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 50
#  grid[i][j] is either 0 or 1.
#  
#  

import collections
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        area = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 1:
                    area = max(area, self.calculateArea(grid, i, j))

        return area
    
    def calculateArea(self, grid: List[List[int]], i, j) -> int:
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        q = collections.deque()
        q.append((i, j))
        grid[i][j] = 0

        area = 0
        while len(q) > 0:
            px, py = q.popleft()
            area += 1

            for dx, dy in directions:
                x = px + dx
                y = py + dy
                if 0 <= x < len(grid) and 0 <= y < len(grid[x]) and grid[x][y] == 1:
                    q.append((x, y))
                    grid[x][y] = 0

        return area