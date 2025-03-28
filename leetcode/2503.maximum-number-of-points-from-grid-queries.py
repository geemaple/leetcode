#  Tag: Array, Two Pointers, Breadth-First Search, Union Find, Sorting, Heap (Priority Queue), Matrix
#  Time: O(KlogK + KNM * log(NM))
#  Space: O(K + NM)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/mg_R41oWzTM

#  You are given an m x n integer matrix grid and an array queries of size k.
#  Find an array answer of size k such that for each integer queries[i] you start in the top left cell of the matrix and repeat the following process:
#  
#  If queries[i] is strictly greater than the value of the current cell that you are in, then you get one point if it is your first time visiting this cell, and you can move to any adjacent cell in all 4 directions: up, down, left, and right.
#  Otherwise, you do not get any points, and you end this process.
#  
#  After the process, answer[i] is the maximum number of points you can get. Note that for each query you are allowed to visit the same cell multiple times.
#  Return the resulting array answer.
#   
#  Example 1:
#  
#  
#  Input: grid = [[1,2,3],[2,5,7],[3,5,1]], queries = [5,6,2]
#  Output: [5,8,1]
#  Explanation: The diagrams above show which cells we visit to get points for each query.
#  Example 2:
#  
#  
#  Input: grid = [[5,2,1],[1,1,2]], queries = [3]
#  Output: [0]
#  Explanation: We can not get any points because the value of the top left cell is already greater than or equal to 3.
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  2 <= m, n <= 1000
#  4 <= m * n <= 105
#  k == queries.length
#  1 <= k <= 104
#  1 <= grid[i][j], queries[i] <= 106
#  
#  

import heapq
class Solution:
    def maxPoints(self, grid: List[List[int]], queries: List[int]) -> List[int]:

        directions = [-1, 0, 1, 0, -1]
        n = len(grid)
        m = len(grid[0])

        index_query = [(queries[i], i) for i in range(len(queries))]
        index_query.sort()

        heap = [(grid[0][0], 0, 0)]
        visited = set()
        visited.add((0, 0))

        count = 0
        res = [0 for i in range(len(queries))]

        for val, i in index_query:
            while len(heap) > 0 and heap[0][0] < val:
                _, x, y = heapq.heappop(heap)
                count += 1
                for d in range(4):
                    dx = x + directions[d]
                    dy = y + directions[d + 1]
                    if 0 <= dx < n and 0 <= dy < m and (dx, dy) not in visited:
                        visited.add((dx, dy))
                        heapq.heappush(heap, (grid[dx][dy], dx, dy))
            res[i] = count

        return res