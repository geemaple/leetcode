#  Tag: Array, Math, Sorting, Matrix
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/X6gPhyfPNbA

#  You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
#  A uni-value grid is a grid where all the elements of it are equal.
#  Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
#   
#  Example 1:
#  
#  
#  Input: grid = [[2,4],[6,8]], x = 2
#  Output: 4
#  Explanation: We can make every element equal to 4 by doing the following: 
#  - Add x to 2 once.
#  - Subtract x from 6 once.
#  - Subtract x from 8 twice.
#  A total of 4 operations were used.
#  
#  Example 2:
#  
#  
#  Input: grid = [[1,5],[2,3]], x = 1
#  Output: 5
#  Explanation: We can make every element equal to 3.
#  
#  Example 3:
#  
#  
#  Input: grid = [[1,2],[3,4]], x = 2
#  Output: -1
#  Explanation: It is impossible to make every element equal.
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 105
#  1 <= m * n <= 105
#  1 <= x, grid[i][j] <= 104
#  
#  

class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        n = len(grid)
        m = len(grid[0])
        table = [grid[i][j] for i in range(n) for j in range(m)]

        table.sort()
        mid = (len(table) - 1) // 2
        if len(table) % 2 == 1:
            return self.cal(table, table[mid], x)
        else:
            return min(self.cal(table, table[mid], x), self.cal(table, table[mid + 1], x))


    def cal(self, table: list, target: int, x: int) -> int:
        res = 0
        for num in table:
            if abs(num - target) % x != 0:
                return -1

            res += abs(num - target) // x
        return res
    
class Solution:
    def minOperations(self, grid: List[List[int]], x: int) -> int:
        n = len(grid)
        m = len(grid[0])
        table = [grid[i][j] for i in range(n) for j in range(m)]
        
        table.sort()
        dp = [0] * len(table)
        
        for i in range(1, len(table)):
            if (table[i] - table[i - 1]) % x:
                return -1
            dp[i] = dp[i - 1] + i * (table[i] - table[i - 1]) // x
        
        op = 0
        res = float('inf')
        
        for i in range(len(table) - 1, 0, -1):
            op += (len(table) - i) * (table[i] - table[i - 1]) // x
            res = min(res, op + dp[i - 1])
        
        return 0 if res == float('inf') else res