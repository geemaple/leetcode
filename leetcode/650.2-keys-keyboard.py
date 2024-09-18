#  Tag: Math, Dynamic Programming
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
#  
#  Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
#  Paste: You can paste the characters which are copied last time.
#  
#  Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
#   
#  Example 1:
#  
#  Input: n = 3
#  Output: 3
#  Explanation: Initially, we have one character 'A'.
#  In step 1, we use Copy All operation.
#  In step 2, we use Paste operation to get 'AA'.
#  In step 3, we use Paste operation to get 'AAA'.
#  
#  Example 2:
#  
#  Input: n = 1
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= n <= 1000
#  
#  

class Solution:
    def minSteps(self, n: int) -> int:
        dp = [0 for i in range(n + 1)]

        for i in range(2, n + 1):
            dp[i] = i        
            for j in range(2, n + 1):
                if i % j == 0:
                    dp[i] = j + dp[i // j]
                    break

        return dp[n]

class Solution:
    def minSteps(self, n: int) -> int:
        dp = [[float('inf') for j in range(n + 1)] for i in range(n + 1)]
        dp[1][0] = 0

        for i in range(1, n + 1):
            for j in range(n + 1):
                if j > 0 and i + j <= n:
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1)
                if j < i:
                    dp[i][i] = min(dp[i][i], dp[i][j] + 1)

        return min(dp[n])
    
class Solution:
    def minSteps(self, n: int) -> int:
        res = 0
        for i in range(2, n + 1):
            while n % i == 0:
                res += i
                n = n // i

        return res