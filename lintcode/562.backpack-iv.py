#  Tag: Backpack DP, Dynamic Programming/DP
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Give `n` items and an array, `num[i]` indicate the size of `i`th item.
#  An integer `target` denotes the size of backpack.
#  Find the number of ways to fill the backpack.
#  
#  `Each item may be chosen unlimited number of times`
#  
#  **Example1**
#  
#  ```
#  Input: nums = [2,3,6,7] and target = 7
#  Output: 2
#  Explanation:
#  Solution sets are: 
#  [7]
#  [2, 2, 3]
#  ```
#  
#  **Example2**
#  
#  ```
#  Input: nums = [2,3,4,5] and target = 7
#  Output: 3
#  Explanation:
#  Solution sets are: 
#  [2, 5]
#  [3, 4]
#  [2, 2, 3]
#  ```
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param nums: an integer array and all positive numbers, no duplicates
    @param target: An integer
    @return: An integer
    """
    def back_pack_i_v(self, nums: List[int], target: int) -> int:
        # write your code here
        n = len(nums)
        dp = [[0] * (target + 1) for i in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for i in range(1, n + 1):
            for j in range(1, target + 1):
                dp[i][j] = dp[i - 1][j]
                weight = nums[i - 1]
                if j >= weight:
                    dp[i][j] += dp[i][j - weight]

        return dp[n][target]
    
class Solution:
    """
    @param nums: an integer array and all positive numbers, no duplicates
    @param target: An integer
    @return: An integer
    """
    def back_pack_i_v(self, nums: List[int], target: int) -> int:
        # write your code here
        n = len(nums)
        dp = [0 for i in range(target + 1)]
        dp[0] = 1

        for i in range(1, n + 1):
            for j in range(1, target + 1):
                weight = nums[i - 1]
                if j >= weight:
                    dp[j] += dp[j - weight]

        return dp[target]