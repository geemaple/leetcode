#  Tag: Array, Two Pointers, Sorting
#  Time: O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
#  Notice that the solution set must not contain duplicate triplets.
#   
#  Example 1:
#  
#  Input: nums = [-1,0,1,2,-1,-4]
#  Output: [[-1,-1,2],[-1,0,1]]
#  Explanation: 
#  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
#  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
#  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
#  The distinct triplets are [-1,0,1] and [-1,-1,2].
#  Notice that the order of the output and the order of the triplets does not matter.
#  
#  Example 2:
#  
#  Input: nums = [0,1,1]
#  Output: []
#  Explanation: The only possible triplet does not sum up to 0.
#  
#  Example 3:
#  
#  Input: nums = [0,0,0]
#  Output: [[0,0,0]]
#  Explanation: The only possible triplet sums up to 0.
#  
#   
#  Constraints:
#  
#  3 <= nums.length <= 3000
#  -105 <= nums[i] <= 105
#  
#  

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for k in range(2, n):
            if k + 1 < n and nums[k] == nums[k + 1]:
                continue
            target = -nums[k]
            l = 0
            r = k - 1
            while l < r:
                if nums[l] + nums[r] == target:
                    res.append([nums[l], nums[r], nums[k]])
                    while l < r and nums[l + 1] == nums[l]:
                        l += 1
                    while l < r and nums[r - 1] == nums[r]:
                        r -= 1
                    l += 1
                    r -= 1
                elif nums[l] + nums[r] > target:
                    r -= 1
                else:
                    l += 1
        return res

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            target = -nums[i]
            history = {}
            j = i + 1
            while j < n:
                tmp = target - nums[j]
                if tmp in history:
                    res.append([nums[i], nums[j], tmp])
                    while j + 1 < n and nums[j] == nums[j + 1]:
                        j += 1
                else:
                    history[nums[j]] = j

                j += 1

        return res