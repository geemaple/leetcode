#  Tag: Array, Breadth-First Search, Graph, Heap (Priority Queue), Matrix, Shortest Path
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an m x n binary matrix grid and an integer health.
#  You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
#  You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
#  Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
#  Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.
#   
#  Example 1:
#  
#  Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
#  Output: true
#  Explanation:
#  The final cell can be reached safely by walking along the gray cells below.
#  
#  Example 2:
#  
#  Input: grid = [[0,1,1,0,0,0],[1,0,1,0,0,0],[0,1,1,1,0,1],[0,0,1,0,1,0]], health = 3
#  Output: false
#  Explanation:
#  A minimum of 4 health points is needed to reach the final cell safely.
#  
#  Example 3:
#  
#  Input: grid = [[1,1,1],[1,0,1],[1,1,1]], health = 5
#  Output: true
#  Explanation:
#  The final cell can be reached safely by walking along the gray cells below.
#  
#  Any path that does not go through the cell (1, 1) is unsafe since your health will drop to 0 when reaching the final cell.
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 50
#  2 <= m * n
#  1 <= health <= m + n
#  grid[i][j] is either 0 or 1.
#  
#  

import heapq
class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n = len(grid)
        m = len(grid[0])
        heap = [(grid[0][0], 0, 0)]
        directions = [-1, 0, 1, 0, -1]
        visited = set()

        while len(heap) > 0:
            cost, i, j = heapq.heappop(heap)

            if cost == health:
                return False

            if i == n - 1 and j == m - 1:
                return True

            if (i, j) in visited:
                continue

            visited.add((i, j))

            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]
                if 0 <= x < n and 0 <= y < m and (x, y) not in visited:
                    heapq.heappush(heap, (cost + grid[x][y], x, y))

        return False