#  Tag: Opposite Direction Two Pointers, Greedy, Two Pointers
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array of positive integers **with subscripts starting at 0** `nums`, an operation can be performed to select **any two neighbouring elements in `nums` to be merged and replaced with the sum of the two numbers**, i.e.
#  if `nums = [1, 2, 3, 1]`, `nums[1]` and `nums[2]` can be merged and replaced so that `nums` becomes `[1, 5, 1]`.
#  
#  Returns **the minimum number of operations required to turn `nums` into a palindrome.**
#  
#  Example 1:
#  
#  ```
#  Input:
#  nums = [4, 3, 2, 1, 2, 3, 1]
#  Output:
#  2
#  Explanation:
#  Merge nums[3] and nums[4] -> nums = [4, 3, 2, 3, 3, 1]
#  Merge nums[4] and nums[5] -> nums = [4, 3, 2, 3, 4]
#  ```
#  
#  Example 2:
#  
#  ```
#  Input:
#  nums = [1, 2, 3, 1]
#  Output:
#  1
#  Explanation:
#  Merge nums[1] and nums[2] -> nums = [1, 5, 1]
#  ```
#  
#  Example 3:
#  
#  ```
#  Input:
#  nums = [1, 2, 3, 4]
#  Output:
#  3
#  Explanation:
#  3 times merge of any position, finally nums = [10]
#  ```
#  
#  - $1 \leq nums.length \leq 10^5$
#  - $1 \leq nums[i] \leq 10^6$

from typing import (
    List,
)

class Solution:
    """
    @param nums: An integer array
    @return: Minimum number of operations to turn array into a palindrome
    """
    def minimum_operations(self, nums: List[int]) -> int:
        # write your code here
        l = 0
        r = len(nums) - 1
        res = 0
        while l < r:
            if nums[l] == nums[r]:
                l += 1
                r -= 1
            elif nums[l] < nums[r]:
                res += 1
                nums[l + 1] += nums[l]
                l += 1
            else:
                res += 1
                nums[r - 1] += nums[r]
                r -= 1
                
        return res