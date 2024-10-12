#  Tag: Binary Search on Answer, Binary Search
#  Time: O(Nlog(A/ε))
#  Space: O(N)
#  Ref: Leetcode-644
#  Note: -

#  Given an array with positive and negative numbers, find the `maximum average subarray` which length should be greater or equal to given length `k`.
#  
#  ---
#  
#  Example 1:
#  ```
#  Input:
#  [1,12,-5,-6,50,3]
#  3
#  Output:
#  15.667
#  Explanation:
#   (-6 + 50 + 3) / 3 = 15.667
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  [5]
#  1
#  Output:
#  5.000
#  ```
#  
#  It's guaranteed that the size of the array is greater or equal to *k*.
#  Only unsigned `0` results are allowed to pass when `0` is the return value

from typing import (
    List,
)

class Solution:
    """
    @param nums: an array with positive and negative numbers
    @param k: an integer
    @return: the maximum average
    """
    def max_average(self, nums: List[int], k: int) -> float:
        # write your code here
        left = min(nums)
        right = max(nums)

        while right - left > 1e-5:
            mid = (left +right) / 2.0
            if self.fit(nums, k, mid):
                left = mid
            else:
                right = mid

        return left

    def fit(self, nums: list, k: int, average:int) -> bool:
        prefix = [0]
        for i in range(len(nums)):
            prefix.append(prefix[-1] + nums[i] - average)

        min_prefix = 0
        for i in range(k, len(prefix)):
            if prefix[i] - min_prefix >= 0:
                return True;

            min_prefix = min(min_prefix, prefix[i - k + 1])

        return False

