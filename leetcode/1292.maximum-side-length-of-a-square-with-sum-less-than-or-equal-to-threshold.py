#  Tag: Array, Binary Search, Matrix, Prefix Sum
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.
#   
#  Example 1:
#  
#  
#  Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
#  Output: 2
#  Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
#  
#  Example 2:
#  
#  Input: mat = [[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2],[2,2,2,2,2]], threshold = 1
#  Output: 0
#  
#   
#  Constraints:
#  
#  m == mat.length
#  n == mat[i].length
#  1 <= m, n <= 300
#  0 <= mat[i][j] <= 104
#  0 <= threshold <= 105
#  
#  

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)
        n = len(mat[0])

        dp = [[0] * (n + 1) for i in range(m + 1)]
        l  = 1
        res = 0
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1]
                if (i >= l and j >= l and dp[i][j] - dp[i - l][j] - dp[i][j - l] + dp[i - l][j - l] <= threshold):
                    res = l
                    l += 1
        return res

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m = len(mat)
        n = len(mat[0])

        dp = [[0] * (n + 1) for i in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1]

        def check(l: int) -> bool:
            for i in range(l, m + 1):
                for j in range(l, n + 1):
                    if dp[i][j] - dp[i - l][j] - dp[i][j - l] + dp[i - l][j - l] <= threshold:
                        return True

            return False


        left = 0
        right = min(m, n)
        while left < right:
            mid = left + (right - left + 1) // 2
            if check(mid):
                left = mid
            else:
                right = mid - 1

        return left
