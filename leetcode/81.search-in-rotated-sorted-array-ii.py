#  Tag: Array, Binary Search
#  Time: O(logN) ~ O(N)
#  Space: O(1)
#  Ref: -
#  Note: Rotated;

#  There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
#  Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
#  Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
#  You must decrease the overall operation steps as much as possible.
#   
#  Example 1:
#  Input: nums = [2,5,6,0,0,1,2], target = 0
#  Output: true
#  Example 2:
#  Input: nums = [2,5,6,0,0,1,2], target = 3
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 5000
#  -104 <= nums[i] <= 104
#  nums is guaranteed to be rotated at some pivot.
#  -104 <= target <= 104
#  
#   
#  Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
#  

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        left = 0
        right = len(nums) - 1
        while left < right:
            if nums[left] == nums[right]:
                right -= 1
                continue
            
            mid = left + (right - left) // 2
            if nums[mid] >= nums[left]:
                if target >= nums[left] and target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1
            else:
                if target > nums[right] or target <= nums[mid]:
                    right = mid
                else:
                    left = mid + 1

        return nums[left] == target
    

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        left = 0
        right = n - 1

        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return True

            if nums[left] == nums[right]:
                left += 1
                continue

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

        return nums[left] == target