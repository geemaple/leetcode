#  Tag: Array, Two Pointers, Sorting
#  Time: O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
#  Return the sum of the three integers.
#  You may assume that each input would have exactly one solution.
#   
#  Example 1:
#  
#  Input: nums = [-1,2,1,-4], target = 1
#  Output: 2
#  Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
#  
#  Example 2:
#  
#  Input: nums = [0,0,0], target = 1
#  Output: 0
#  Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
#  
#   
#  Constraints:
#  
#  3 <= nums.length <= 500
#  -1000 <= nums[i] <= 1000
#  -104 <= target <= 104
#  
#  

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        res = float('inf')
        for k in range(2, n):
            l = 0
            r = k - 1
            while l < r:
                tmp = nums[l] + nums[r] + nums[k]
                if abs(res - target) > abs(tmp - target):
                    res = tmp

                if tmp == target:
                    break
                elif tmp > target:
                    r -= 1
                else:
                    l += 1
        return res
