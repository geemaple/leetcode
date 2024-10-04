#  Tag: Array, Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: std::lower_bound;
#  Video: https://youtu.be/y6OT8heV-30

#  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
#  If target is not found in the array, return [-1, -1].
#  You must write an algorithm with O(log n) runtime complexity.
#   
#  Example 1:
#  Input: nums = [5,7,7,8,8,10], target = 8
#  Output: [3,4]
#  Example 2:
#  Input: nums = [5,7,7,8,8,10], target = 6
#  Output: [-1,-1]
#  Example 3:
#  Input: nums = [], target = 0
#  Output: [-1,-1]
#  
#   
#  Constraints:
#  
#  0 <= nums.length <= 105
#  -109 <= nums[i] <= 109
#  nums is a non-decreasing array.
#  -109 <= target <= 109
#  
#  

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

        first = self.lower_bound(nums, target)
        if first == len(nums) or nums[first] != target:
            return [-1, -1]
        
        last = self.lower_bound(nums, target + 1) - 1

        return [first, last]


    def lower_bound(self, nums, target):
        start = 0
        end = len(nums)

        while start < end:

            mid = start + (end - start) // 2

            if nums[mid] < target:
                start = mid + 1
            else:
                end = mid
            
        return start