#  Tag: Binary Search, Two Pointers, Array
#  Time: O(NlogA)
#  Space: O(1)
#  Ref: Leetcode-1918
#  Note: -

#  Given an array of positive integers `n` of length `nums` and an integer `k`, return the sum of **the $k^{th}$ smallest subarray of `nums`.**
#  
#  Example 1:
#  ```
#  Input:
#  nums = [1, 2, 3]
#  k = 4
#  Output:
#  3
#  Explanation:
#  The subarrays of [1, 2, 3] are:
#  [1], [2], [3]
#  [1, 2], [2, 3]
#  [1, 2, 3]
#  The subarray sums are in ascending order: 1, 2, 3, 3, 5, 6
#  The fourth smallest subarray sum is 3
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  nums = [2, 2, 6, 6]
#  k = 6
#  Output:
#  8
#  Explanation:
#  The subarrays of [2, 2, 6, 6] are:
#  [2], [2], [6], [6]
#  [2, 2], [2, 6], [6, 6]
#  [2, 2, 6], [2, 6, 6]
#  [2, 2, 6, 6]
#  The subarray sums are in ascending order: 2, 2, 4, 6, 6, 8, 10, 12, 14, 16
#  The sixth smallest subarray sum is 8
#  
#  ```
#  
#  $1 \leq nums.length \leq 10 ^4$
#  $1 \leq nums[i] \leq 5 * 10^4$
#  $1 \leq k \leq n * (n + 1) \ / \ 2$
#  In an array, a subarray is formed from one or more consecutive array elements. The subarray should contain at least one element

from typing import (
    List,
)

import heapq
class Solution:
    """
    @param nums: An integer array
    @param k: A positive integer
    @return: Return the kth smallest subarray sum
    """
    def kth_smallest_subarray_sum(self, nums: List[int], k: int) -> int:
        # write your code here
        left = min(nums)
        right = sum(nums)
        while left < right:
            mid = left + (right - left) // 2
            if self.count(nums, mid) < k:
                left = mid + 1
            else:
                right = mid

        return left

    def count(self, nums: list, target: int) -> int:
        n = len(nums)
        count = 0
        i = 0
        res = 0
        for j in range(n):
            count += nums[j]
            while count > target:
                count -= nums[i]
                i += 1

            res += j - i + 1
        return res