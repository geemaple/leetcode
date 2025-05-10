#  Tag: Opposite Direction Two Pointers, Enumerate, Two Pointers, Array
#  Time: O(N^2)
#  Space: O(1)
#  Ref: Leetcode-259
#  Note: -

#  Given an array of `n` integers nums and a `target`, find the number of index triplets `i, j, k` with `0 <= i < j < k < n` that satisfy the condition `nums[i] + nums[j] + nums[k] < target`.
#  
#  **Example1**
#  
#  ```
#  Input:  nums = [-2,0,1,3], target = 2
#  Output: 2
#  Explanation:
#  Because there are two triplets which sums are less than 2:
#  [-2, 0, 1]
#  [-2, 0, 3]
#  ```
#  
#  **Example2**
#  
#  ```
#  Input: nums = [-2,0,-1,3], target = 2
#  Output: 3
#  Explanation:
#  Because there are three triplets which sums are less than 2:
#  [-2, 0, -1]
#  [-2, 0, 3]
#  [-2, -1, 3]
#  ```
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param nums:  an array of n integers
    @param target: a target
    @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
    """
    def three_sum_smaller(self, nums: List[int], target: int) -> int:
        # Write your code here
        n = len(nums)
        nums.sort()
        res = 0
        for i in range(n - 2):
            l = i + 1
            r = n - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] < target:
                    res += r - l
                    l += 1
                else:
                    r -= 1

        return res