#  Tag: Array, Binary Search, Depth-First Search, Breadth-First Search, Union Find, Heap (Priority Queue), Matrix
#  Time: O(N^2 * logN)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
#  The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
#  Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).
#   
#  Example 1:
#  
#  
#  Input: grid = [[0,2],[1,3]]
#  Output: 3
#  Explanation:
#  At time 0, you are in grid location (0, 0).
#  You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
#  You cannot reach point (1, 1) until time 3.
#  When the depth of water is 3, we can swim anywhere inside the grid.
#  
#  Example 2:
#  
#  
#  Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
#  Output: 16
#  Explanation: The final route is shown.
#  We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
#  
#   
#  Constraints:
#  
#  n == grid.length
#  n == grid[i].length
#  1 <= n <= 50
#  0 <= grid[i][j] < n2
#  Each value grid[i][j] is unique.
#  
#  

import heapq
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        heap = [(grid[0][0], 0 , 0)]
        visited = set()
        directions = [-1, 0, 1, 0, -1]

        res = 0
        while len(heap) > 0:
            h, i, j = heap[0]
            heapq.heappop(heap)
            if (i, j) not in visited:
                visited.add((i, j))
                res = max(res, h)
                if i == n - 1 and j == n - 1:
                    return res

                for d in range(4):
                    x = i + directions[d]
                    y = j + directions[d + 1]
                    if 0 <= x < n and 0 <= y < n and (x, y) not in visited:
                        heapq.heappush(heap, (grid[x][y], x, y))

from collections import deque
class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        left = 0
        right = 2500
        while left < right:
            mid = left + (right - left) // 2
            if self.can_swim(grid, mid):
                right = mid
            else:
                left = mid + 1

        return left
    
    def can_swim(self, grid: list, t: int) -> bool:
        if grid[0][0] > t:
            return False

        n = len(grid)
        q = deque()
        visited = set()
        q.append((0, 0))
        visited.add((0, 0))
        directions = [-1, 0, 1, 0, -1]

        while len(q) > 0:
            i, j = q.popleft()
            if i == n - 1 and j == n - 1:
                return True

            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]
                if 0 <= x < n and 0 <= y < n and grid[x][y] <= t and (x, y) not in visited:
                    visited.add((x, y))
                    q.append((x, y))

        return False