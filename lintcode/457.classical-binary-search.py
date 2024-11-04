#  Tag: Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Find any position of a target number in a sorted array.
#  Return `-1` if target does not exist.
#  
#  ---
#   
#  
#  **Example 1:**
#  ```
#  Input: nums = [1,2,2,4,5,5], target = 2
#  Output: 1 or 2
#  ```
#  **Example 2:**
#  ```
#  Input: nums = [1,2,2,4,5,5], target = 6
#  Output: -1
#  ```
#  
#  

class Solution:
    """
    @param nums: An integer array sorted in ascending order
    @param target: An integer
    @return: An integer
    """
    def findPosition(self, nums, target):
        # write your code here
        n = len(nums)
        start = 0
        end = n

        while start < end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return mid

            if nums[mid] < target:
                start = mid + 1
            else:
                end = mid

        return -1
    
class Solution:
    """
    @param nums: An integer array sorted in ascending order
    @param target: An integer
    @return: An integer
    """
    def findPosition(self, nums, target):
        # write your code here
        n = len(nums)
        if n == 0:
            return -1

        left = 0
        right = n - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid

            if nums[mid] < target:
                left = mid + 1
            else:
                right = mid

        return -1 if nums[left] != target else left

