#  Tag: Backpack DP, Dynamic Programming/DP
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Given `n` kinds of items, and each kind of item has an infinite number available.
#  The `i-th` item has size `A[i]` and value `V[i]`.
#  
#  Also given a backpack with size `m`.
#  What is the maximum value you can put into the backpack?
#  
#  **Example 1:**
#  
#  ```
#  Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10
#  Output: 15
#  Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: A = [1, 2, 3], V = [1, 2, 3], m = 5
#  Output: 5
#  Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.
#  ```
#  
#  1. You cannot divide item into small pieces.
#  2. Total size of items you put into backpack can not exceed `m`.

from typing import (
    List,
)

class Solution:
    """
    @param a: an integer array
    @param v: an integer array
    @param m: An integer
    @return: an array
    """
    def back_pack_i_i_i(self, a: List[int], v: List[int], m: int) -> int:
        # write your code here
        n = len(a)
        dp = [[0] * (m + 1) for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                weight = a[i - 1]
                value = v[i - 1]
                dp[i][j] = dp[i - 1][j]
                if j >= weight:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - weight] + value)

        return dp[n][m]
    
class Solution:
    """
    @param a: an integer array
    @param v: an integer array
    @param m: An integer
    @return: an array
    """
    def back_pack_i_i_i(self, a: List[int], v: List[int], m: int) -> int:
        # write your code here
        n = len(a)
        dp = [0 for i in range(m + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                weight = a[i - 1]
                value = v[i - 1]
                if j >= weight:
                    dp[j] = max(dp[j], dp[j - weight] + value)

        return dp[m]