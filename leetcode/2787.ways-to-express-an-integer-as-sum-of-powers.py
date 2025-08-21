#  Tag: Dynamic Programming
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/UjpU8Ly4k1s

#  Given two positive integers n and x.
#  Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
#  Since the result can be very large, return it modulo 109 + 7.
#  For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.
#   
#  Example 1:
#  
#  Input: n = 10, x = 2
#  Output: 1
#  Explanation: We can express n as the following: n = 32 + 12 = 10.
#  It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
#  
#  Example 2:
#  
#  Input: n = 4, x = 1
#  Output: 2
#  Explanation: We can express n in the following ways:
#  - n = 41 = 4.
#  - n = 31 + 11 = 4.
#  
#   
#  Constraints:
#  
#  1 <= n <= 300
#  1 <= x <= 5
#  
#  

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9 + 7
        dp = [[0] * (n + 1) for _ in range(n + 1)]
        
        dp[0][0] = 1
        for i in range(1, n + 1):
            v = pow(i, x)
            
            for j in range(0, n + 1):
                if j >= v:
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - v]) % mod
                else:
                    dp[i][j] = dp[i - 1][j]
        
        return dp[n][n]

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9 + 7
        dp = [0] * (n + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            v = pow(i, x)
            if v > n:
                break

            for j in range(n, v - 1, -1):
                dp[j] = (dp[j] + dp[j - v]) % mod
     
        return dp[n]
