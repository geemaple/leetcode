#  Tag: Array, Dynamic Programming, Matrix
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/YuuDix0yiIQ

#  Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
#   
#  Example 1:
#  
#  Input: matrix =
#  [
#    [0,1,1,1],
#    [1,1,1,1],
#    [0,1,1,1]
#  ]
#  Output: 15
#  Explanation: 
#  There are 10 squares of side 1.
#  There are 4 squares of side 2.
#  There is  1 square of side 3.
#  Total number of squares = 10 + 4 + 1 = 15.
#  
#  Example 2:
#  
#  Input: matrix = 
#  [
#    [1,0,1],
#    [1,1,0],
#    [1,1,0]
#  ]
#  Output: 7
#  Explanation: 
#  There are 6 squares of side 1.  
#  There is 1 square of side 2. 
#  Total number of squares = 6 + 1 = 7.
#  
#   
#  Constraints:
#  
#  1 <= arr.length <= 300
#  1 <= arr[0].length <= 300
#  0 <= arr[i][j] <= 1
#  
#  

class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])

        dp = [[0] * n for i in range(m)]
        res = 0

        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    dp[i][j] = matrix[i][j]
                elif matrix[i][j] == 1:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1

                res += dp[i][j]

        return res