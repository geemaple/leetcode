#  Tag: Backpack DP, Dynamic Programming/DP
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Given `n` items with size $A_{i}$ an integer `m` denotes the size of a backpack.
#  How full you can fill this backpack?
#  (Each item can only be selected once and the size of the item is a positive integer)
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  array = [3,4,8,5]
#  backpack size = 10
#  ``` 
#  Output:  
#  ``` 
#  9
#  ``` 
#  Explanation:  
#  
#  Load 4 and 5.
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  array = [2,3,5,7]
#  backpack size = 12
#  ``` 
#  Output:  
#  ``` 
#  12
#  ``` 
#  Explanation:  
#  
#  Load 5 and 7.
#  
#  * You can not divide any item into small pieces.
#  * $n \lt 1000$
#  * $m \lt 1e9$

from typing import (
    List,
)

class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @return: The maximum size
    """
    def back_pack(self, m: int, a: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [[0 for j in range(m + 1)] for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                v = w = a[i - 1]
                if j >= w:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v)
                else:
                    dp[i][j] = dp[i - 1][j]

        return dp[n][m]
    
class Solution:
    """
    @param m: An integer m denotes the size of a backpack
    @param a: Given n items with size A[i]
    @return: The maximum size
    """
    def back_pack(self, m: int, a: List[int]) -> int:
        # write your code here
        n = len(a)
        dp = [0 for j in range(m + 1)]

        for i in range(1, n + 1):
            for j in range(m, 0, -1):
                v = w = a[i - 1]
                if j >= w:
                    dp[j] = max(dp[j], dp[j - w] + v)

        return dp[m]