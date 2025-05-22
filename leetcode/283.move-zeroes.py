#  Tag: Array, Two Pointers
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#  Note that you must do this in-place without making a copy of the array.
#   
#  Example 1:
#  Input: nums = [0,1,0,3,12]
#  Output: [1,3,12,0,0]
#  Example 2:
#  Input: nums = [0]
#  Output: [0]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 104
#  -231 <= nums[i] <= 231 - 1
#  
#   
#  Follow up: Could you minimize the total number of operations done?

class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != 0:
                nums[fast], nums[slow] = nums[slow], nums[fast]
                slow += 1        


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        l = 0
        i = 0
        while i < n and l < n:
            while l < n and nums[l] != 0:
                l += 1

            i = max(i, l + 1)
            while i < n and nums[i] == 0:
                i += 1

            if i < n and l < n:
                nums[i], nums[l] = nums[l], nums[i]
                i += 1
                l += 1