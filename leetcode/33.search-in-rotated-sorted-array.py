#  Tag: Array, Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: Rotated;

#  There is an integer array nums sorted in ascending order (with distinct values).
#  Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
#  Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
#  You must write an algorithm with O(log n) runtime complexity.
#   
#  Example 1:
#  Input: nums = [4,5,6,7,0,1,2], target = 0
#  Output: 4
#  Example 2:
#  Input: nums = [4,5,6,7,0,1,2], target = 3
#  Output: -1
#  Example 3:
#  Input: nums = [1], target = 0
#  Output: -1
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 5000
#  -104 <= nums[i] <= 104
#  All values of nums are unique.
#  nums is an ascending array that is possibly rotated.
#  -104 <= target <= 104
#  
#  

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while left < right:

            mid = left + (right - left) // 2

            if nums[mid] > nums[right]:
                if nums[right] < target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                else:
                    right = mid

        return left if nums[left] == target else -1
    
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left = 0
        right = n - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return mid

            if target > nums[right]:
                if nums[mid] > nums[right] and nums[mid] < target:
                    left = mid + 1
                else:
                    right = mid
            else:
                if nums[mid] <= nums[right] and nums[mid] >= target:
                    right = mid
                else:
                    left = mid + 1

        return left if nums[left] == target else -1
