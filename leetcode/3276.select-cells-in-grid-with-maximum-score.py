#  Tag: Array, Dynamic Programming, Bit Manipulation, Matrix, Bitmask
#  Time: O(NM*2^N)
#  Space: O(2^N)
#  Ref: -
#  Note: -

#  You are given a 2D matrix grid consisting of positive integers.
#  You have to select one or more cells from the matrix such that the following conditions are satisfied:
#  
#  No two selected cells are in the same row of the matrix.
#  The values in the set of selected cells are unique.
#  
#  Your score will be the sum of the values of the selected cells.
#  Return the maximum score you can achieve.
#   
#  Example 1:
#  
#  Input: grid = [[1,2,3],[4,3,2],[1,1,1]]
#  Output: 8
#  Explanation:
#  
#  We can select the cells with values 1, 3, and 4 that are colored above.
#  
#  Example 2:
#  
#  Input: grid = [[8,7,6],[8,3,2]]
#  Output: 15
#  Explanation:
#  
#  We can select the cells with values 7 and 8 that are colored above.
#  
#   
#  Constraints:
#  
#  1 <= grid.length, grid[i].length <= 10
#  1 <= grid[i][j] <= 100
#  
#  

from collections import defaultdict
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        indexes = defaultdict(set)
        for i in range(n):
            for j in range(m):
                indexes[grid[i][j]].add(i)

        dp = [0 for i in range(1 << n)]
        for v, index in indexes.items():
            for i in range((1 << n) - 1, 0, -1):
                for j in index:
                    if (i >> j & 1):
                        dp[i] = max(dp[i], dp[i ^ (1 << j)] + v)

        return dp[-1]        

from collections import defaultdict
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        indexes = defaultdict(set)
        for i in range(n):
            for j in range(m):
                indexes[grid[i][j]].add(i)

        dp = [0 for i in range(1 << n)]
        for v, index in indexes.items():
            ndp = list(dp)
            for i in range(1, 1 << n):
                for j in index:
                    if (i >> j & 1):
                        ndp[i] = max(ndp[i], dp[i ^ (1 << j)] + v)
            dp = ndp
        return dp[-1]