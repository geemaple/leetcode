#  Tag: Array
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
#  We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).
#   
#  Example 1:
#  
#  Input: nums = [4,2,3]
#  Output: true
#  Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
#  
#  Example 2:
#  
#  Input: nums = [4,2,1]
#  Output: false
#  Explanation: You cannot get a non-decreasing array by modifying at most one element.
#  
#   
#  Constraints:
#  
#  n == nums.length
#  1 <= n <= 104
#  -105 <= nums[i] <= 105
#  
#  

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        count = 0

        for i in range(1, len(nums)):
            if nums[i] < nums[i - 1]:
                count += 1
                if i - 2 >= 0 and nums[i - 2] > nums[i]:
                    nums[i] = nums[i - 1]
                else:
                    nums[i - 1] = nums[i]
                
        return count <= 1
        