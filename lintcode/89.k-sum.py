#  Tag: Backpack DP, Dynamic Programming/DP
#  Time: O(NKT)
#  Space: O(NKT)
#  Ref: -
#  Note: -

#  Given `n` distinct positive integers, integer `k` $(k \leq n)$ and a number `target`.
#  
#  Find `k` numbers where sum is target.
#  Calculate how many solutions there are?
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  A = [1,2,3,4]
#  k = 2
#  target = 5
#  ``` 
#  Output:  
#  ``` 
#  2
#  ``` 
#  Explanation:  
#  
#  1 + 4 = 2 + 3 = 5
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  A = [1,2,3,4,5]
#  k = 3
#  target = 6
#  ``` 
#  Output:  
#  ``` 
#  1
#  ``` 
#  Explanation:  
#  
#  There is only one method. 1 + 2 + 3 = 6
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param a: An integer array
    @param k: A positive integer (k <= length(A))
    @param target: An integer
    @return: An integer
    """
    def k_sum(self, a: List[int], k: int, target: int) -> int:
        # write your code here
        n = len(a)
        dp = [[[0] * (target + 1) for j in range(k + 1)] for i in range(n + 1)]
        dp[0][0][0] = 1

        for i in range(1, n + 1):
            for j in range(k + 1):
                for t in range(target + 1):
                    dp[i][j][t] = dp[i - 1][j][t]
                    if j - 1 >= 0 and a[i - 1] <= t:
                        dp[i][j][t] += dp[i - 1][j - 1][t - a[i - 1]]

        return dp[n][k][target]

class Solution:
    """
    @param a: An integer array
    @param k: A positive integer (k <= length(A))
    @param target: An integer
    @return: An integer
    """
    def k_sum(self, a: List[int], k: int, target: int) -> int:
        # write your code here
        n = len(a)
        dp = [[0] * (target + 1) for j in range(k + 1)]
        dp[0][0] = 1

        for num in a:
            for j in range(k, 0, -1):
                for t in range(target, num - 1, -1):
                    dp[j][t] += dp[j - 1][t - num]

        return dp[k][target]