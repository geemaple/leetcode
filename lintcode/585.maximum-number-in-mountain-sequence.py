#  Tag: Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a mountain sequence of `n` integers which increase firstly and then decrease, find the mountain top(Maximum).
#  
#  ---
#   
#  
#  Example 1:
#  ```
#  Input: nums = [1, 2, 4, 8, 6, 3] 
#  Output: 8
#  ```
#  Example 2:
#  ```
#  Input: nums = [10, 9, 8, 7], 
#  Output: 10
#  ```
#  
#  Arrays are strictly incremented, strictly decreasing

from typing import (
    List,
)

class Solution:
    """
    @param nums: a mountain sequence which increase firstly and then decrease
    @return: then mountain top
    """
    def mountain_sequence(self, nums: List[int]) -> int:
        # write your code here
        n = len(nums)
        left = 0
        right = n - 1
        while left < right:
            mid = left + (right - left) // 2
            if (nums[mid] < nums[mid + 1]):
                left = mid + 1
            else:
                right = mid

        return nums[left]