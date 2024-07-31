#  Tag: Array, Sort, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: Rotated

#  Given a **rotated** sorted array, return it to sorted array in-place.（Ascending）
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  array = [4,5,1,2,3]
#  ``` 
#  Output:  
#  ``` 
#  [1,2,3,4,5]
#  ``` 
#  Explanation:  
#  
#  Restore the rotated sorted array.
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  array = [6,8,9,1,2]
#  ``` 
#  Output:  
#  ``` 
#  [1,2,6,8,9]
#  ``` 
#  Explanation:  
#  
#  Restore the rotated sorted array.
#  
#  What is rotated array?
#  
#  - For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]

from typing import (
    List,
)

class Solution:
    """
    @param nums: An integer array
    @return: nothing
    """
    def recover_rotated_sorted_array(self, nums: List[int]):
        # write your code here
        low = self.find_min(nums)
        if low > 0:
            self.reverse(nums, 0, low - 1)
            self.reverse(nums, low, len(nums) - 1)
            self.reverse(nums, 0, len(nums) - 1)

    def reverse(self, nums: List[int], start: int, end: int):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1

    def find_min(self, nums: List[int]) -> int:
        start = 0
        end = len(nums) - 1

        while start < end:
            mid = start + (end - start) // 2

            if nums[mid] == nums[end]:
                end -= 1
                continue

            if nums[mid] < nums[end]:
                end = mid
            else:
                start = mid + 1            

        return start