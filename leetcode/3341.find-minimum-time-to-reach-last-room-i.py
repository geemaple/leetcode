#  Tag: Array, Graph, Heap (Priority Queue), Matrix, Shortest Path
#  Time: O(NMlog(NM))
#  Space: O(NM)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/fc0ppanEgkY

#  There is a dungeon with n x m rooms arranged as a grid.
#  You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.
#  Return the minimum time to reach the room (n - 1, m - 1).
#  Two rooms are adjacent if they share a common wall, either horizontally or vertically.
#   
#  Example 1:
#  
#  Input: moveTime = [[0,4],[4,4]]
#  Output: 6
#  Explanation:
#  The minimum time required is 6 seconds.
#  
#  At time t == 4, move from room (0, 0) to room (1, 0) in one second.
#  At time t == 5, move from room (1, 0) to room (1, 1) in one second.
#  
#  
#  Example 2:
#  
#  Input: moveTime = [[0,0,0],[0,0,0]]
#  Output: 3
#  Explanation:
#  The minimum time required is 3 seconds.
#  
#  At time t == 0, move from room (0, 0) to room (1, 0) in one second.
#  At time t == 1, move from room (1, 0) to room (1, 1) in one second.
#  At time t == 2, move from room (1, 1) to room (1, 2) in one second.
#  
#  
#  Example 3:
#  
#  Input: moveTime = [[0,1],[1,2]]
#  Output: 3
#  
#   
#  Constraints:
#  
#  2 <= n == moveTime.length <= 50
#  2 <= m == moveTime[i].length <= 50
#  0 <= moveTime[i][j] <= 109
#  
#  

import heapq

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        n = len(moveTime)
        m = len(moveTime[0])

        heap = [(0, 0, 0)]
        directions = [-1, 0, 1, 0, -1]
        visited = set()

        while len(heap) > 0:
            cost, i, j = heapq.heappop(heap)
            if (i, j) in visited:
                continue

            visited.add((i, j))
            if i == n - 1 and j == m - 1:
                return cost

            for d in range(4):
                x = i + directions[d]
                y = j + directions[d + 1]
                if 0 <= x < n and 0 <= y < m and (x, y) not in visited:
                    next_cost = max(moveTime[x][y] + 1, cost + 1)
                    heapq.heappush(heap, (next_cost, x, y))