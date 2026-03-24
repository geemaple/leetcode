#  Tag: Array, Matrix, Prefix Sum
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
#  
#  grid[0][0]
#  an equal frequency of 'X' and 'Y'.
#  at least one 'X'.
#  
#   
#  Example 1:
#  
#  Input: grid = [["X","Y","."],["Y",".","."]]
#  Output: 3
#  Explanation:
#  
#  
#  Example 2:
#  
#  Input: grid = [["X","X"],["X","Y"]]
#  Output: 0
#  Explanation:
#  No submatrix has an equal frequency of 'X' and 'Y'.
#  
#  Example 3:
#  
#  Input: grid = [[".","."],[".","."]]
#  Output: 0
#  Explanation:
#  No submatrix has at least one 'X'.
#  
#   
#  Constraints:
#  
#  1 <= grid.length, grid[i].length <= 1000
#  grid[i][j] is either 'X', 'Y', or '.'.
#  
#  

class Solution:
    def numberOfSubmatrices(self, grid: List[List[str]]) -> int:
        m = len(grid)
        n = len(grid[0])

        x = [[0] * (n + 1) for i in range(m + 1)]
        y = [[0] * (n + 1) for i in range(m + 1)]

        res = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X')
                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y')

                if x[i][j] > 0 and x[i][j] == y[i][j]:
                    res += 1

        return res