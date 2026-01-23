#  Tag: Array, Matrix, Prefix Sum
#  Time: O(N^4)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
#  Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
#   
#  Example 1:
#  
#  
#  Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
#  Output: 3
#  Explanation: The largest magic square has a size of 3.
#  Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
#  - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
#  - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
#  - Diagonal sums: 5+4+3 = 6+4+2 = 12
#  
#  Example 2:
#  
#  
#  Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
#  Output: 2
#  
#   
#  Constraints:
#  
#  m == grid.length
#  n == grid[i].length
#  1 <= m, n <= 50
#  1 <= grid[i][j] <= 106
#  
#  

class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0

        rows = [[0] * (n + 1) for _ in range(m + 1)]
        cols = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                rows[i][j] = grid[i - 1][j - 1] + rows[i][j - 1]
                cols[i][j] = grid[i - 1][j - 1] + cols[i - 1][j]


        for i in range(1, m + 1):
            for j in range(1, n + 1):
                k = min(m - i, n - j)
                while k > res:
                    target = rows[i][j + k] - rows[i][j - 1]
                    d1 = d2 = 0
                    l = 0
                    while l <= k:
                        if target != rows[i + l][j + k] - rows[i + l][j - 1] or \
                        target != cols[i + k][j + l] - cols[i - 1][j + l]:
                            break

                        d1 += grid[i - 1 + l][j - 1 + l]
                        d2 += grid[i - 1 + k - l][j - 1 + l]
                        l += 1

                    res = k if l > k and d1 == target and d2 == target else res
                    k -= 1

        return res + 1