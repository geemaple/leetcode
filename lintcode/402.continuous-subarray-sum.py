#  Tag: Prefix Sum Array, Array
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array, find a continuous subarray where the sum of numbers is the biggest.
#  Your code should return the index of the first number and the index of the last number.
#  (If their are duplicate answer, return the minimum one in lexicographical order)
#  
#  **Example 1:**
#  
#  ```
#  Input: [-3, 1, 3, -3, 4]
#  Output: [1, 4]
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: [0, 1, 0, 1]
#  Output: [0, 3]
#  Explanation: The minimum one in lexicographical order.
#  ```
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param a: An integer array
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def continuous_subarray_sum(self, a: List[int]) -> List[int]:
        # write your code here
        n = len(a)
        prefix = [0 for i in range(n + 1)]

        l = 0
        r = 0
        min_index = 0
        for i in range(n):
            prefix[i + 1] = prefix[i] + a[i]

            if prefix[i + 1] - prefix[min_index] > prefix[r + 1] - prefix[l]:
                l = min_index
                r = i

            if prefix[min_index] > prefix[i + 1]:
                min_index = i + 1

        return [l, r]

class Solution:
    """
    @param a: An integer array
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def continuous_subarray_sum(self, a: List[int]) -> List[int]:
        # write your code here
        n = len(a)
        dp = [0 for i in range(n)]
        dp[0] = a[0]

        j = 0
        l = 0
        r = 0
        for i in range(1, n):
            if dp[i - 1] >= 0:
                dp[i] = dp[i - 1] + a[i]
            else:
                dp[i] = a[i]
                j = i

            if dp[i] > dp[r]:
                r = i
                l = j

        return [l, r]