#  Tag: Array, Breadth-First Search, Heap (Priority Queue), Matrix
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
#   
#  Example 1:
#  
#  
#  Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
#  Output: 4
#  Explanation: After the rain, water is trapped between the blocks.
#  We have two small ponds 1 and 3 units trapped.
#  The total volume of water trapped is 4.
#  
#  Example 2:
#  
#  
#  Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
#  Output: 10
#  
#   
#  Constraints:
#  
#  m == heightMap.length
#  n == heightMap[i].length
#  1 <= m, n <= 200
#  0 <= heightMap[i][j] <= 2 * 104
#  
#  

import heapq
class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n = len(heightMap)
        m = len(heightMap[0])
        heap = []

        visited = set()
        for i in range(n):
            heapq.heappush(heap, (heightMap[i][0], (i , 0)))
            heapq.heappush(heap, (heightMap[i][m - 1], (i, m - 1)))
            visited.add((i, 0))
            visited.add((i, m - 1))

        for j in range(m):
            heapq.heappush(heap, (heightMap[0][j], (0, j)))
            heapq.heappush(heap, (heightMap[n - 1][j], (n - 1, j)))
            visited.add((0, j))
            visited.add((n - 1, j))

        res = 0
        directions = [-1, 0, 1, 0, -1]
        while len(heap) > 0:
            h, (i, j) = heapq.heappop(heap)
            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]
                if 0 <= x < n and 0 <= y < m and (x, y) not in visited:
                    visited.add((x, y))
                    heapq.heappush(heap, (max(h, heightMap[x][y]), (x, y)))
                    res += max(0, h - heightMap[x][y])

        return res