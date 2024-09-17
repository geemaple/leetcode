#  Tag: Backpack DP, Dynamic Programming/DP
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  There are `n` items and a backpack with size `m`.
#  Given array `A` representing the size of each item and array `V` representing the value of each item.
#  
#  What's the maximum value can you put into the backpack?
#  
#  **Example 1:**
#   
#  Input:
#  ``` 
#  m = 10
#  A = [2, 3, 5, 7]
#  V = [1, 5, 2, 4]
#  ``` 
#  Output:
#  ```
#  9
#  ```
#  Explanation:
#  
#  Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9 
#  
#  **Example 2:**
#   
#  Input:
#  ``` 
#  m = 10
#  A = [2, 3, 8]
#  V = [2, 5, 8]
#  ``` 
#  Output:
#  ```
#  10
#  ```
#  Explanation:
#  
#  Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10
#  
#  1. `A[i], V[i], n, m` are all integers.
#  2. You can not split an item.
#  3. The sum size of the items you want to put into backpack can not exceed `m`.
#  4. Each item can only be picked up once
#  5. $m <= 1000$\
#  $len(A),len(V)<=100$

from typing import (
    List,
)

class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @param v: Given n items with value V[i]
    @return: The maximum value
    """
    def back_pack_i_i(self, m: int, a: List[int], v: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [[0] * (m + 1) for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                weight = a[i - 1]
                value = v[i - 1]

                if j >= weight:
                    dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j])
                else:
                    dp[i][j] = dp[i - 1][j]

        return dp[n][m]

    
class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @param v: Given n items with value V[i]
    @return: The maximum value
    """
    def back_pack_i_i(self, m: int, a: List[int], v: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [0 for i in range(m + 1)]

        for i in range(1, n + 1):
            for j in range(m, 1, -1):
                weight = a[i - 1]
                value = v[i - 1]
                if j >= weight:
                    dp[j] = max(dp[j], dp[j - weight] + value)

        return dp[m]
