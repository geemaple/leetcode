#  Tag: Math, Dynamic Programming, Memoization
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are climbing a staircase. It takes n steps to reach the top.
#  Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
#   
#  Example 1:
#  
#  Input: n = 2
#  Output: 2
#  Explanation: There are two ways to climb to the top.
#  1. 1 step + 1 step
#  2. 2 steps
#  
#  Example 2:
#  
#  Input: n = 3
#  Output: 3
#  Explanation: There are three ways to climb to the top.
#  1. 1 step + 1 step + 1 step
#  2. 1 step + 2 steps
#  3. 2 steps + 1 step
#  
#   
#  Constraints:
#  
#  1 <= n <= 45
#  
#  

class Solution:
    def climbStairs(self, n: int) -> int:
        cur = 1
        pre = 1

        for i in range(2, n + 1):
            new_cur = pre + cur
            pre = cur
            cur = new_cur

        return cur

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = [1 for i in range(n + 1)]
        for i in range(2, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]