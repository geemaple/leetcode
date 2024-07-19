#  Tag: Math, Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
#  Return the maximum product you can get.
#   
#  Example 1:
#  
#  Input: n = 2
#  Output: 1
#  Explanation: 2 = 1 + 1, 1 × 1 = 1.
#  
#  Example 2:
#  
#  Input: n = 10
#  Output: 36
#  Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
#  
#   
#  Constraints:
#  
#  2 <= n <= 58
#  
#  

class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1 for i in range(n + 1)]

        for i in range(2, n + 1):
            for j in range(1, i):
                left = max(i - j, dp[i - j])
                right = max(j, dp[j])
                dp[i] = max(dp[i], left * right) 

        return dp[n]


class Solution:
    def integerBreak(self, n: int) -> int:
        dp = [1 for i in range(n + 1)]

        for i in range(2, n + 1):
            if i > 2:
                dp[i] = 2 * max(dp[i - 2], i - 2)

            if i > 3:
                dp[i] = max(dp[i], 3 * max(dp[i - 3], i - 3))

        return dp[n]

class Solution:
    def integerBreak(self, n: int) -> int:
        
        if n < 4:
            return n - 1

        res = 1
        while n > 4:
            res = res * 3
            n -= 3
        res = res * n

        return res