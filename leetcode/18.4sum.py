#  Tag: Array, Two Pointers, Sorting
#  Time: O(N^3)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
#  
#  0 <= a, b, c, d < n
#  a, b, c, and d are distinct.
#  nums[a] + nums[b] + nums[c] + nums[d] == target
#  
#  You may return the answer in any order.
#   
#  Example 1:
#  
#  Input: nums = [1,0,-1,0,-2,2], target = 0
#  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
#  
#  Example 2:
#  
#  Input: nums = [2,2,2,2,2], target = 8
#  Output: [[2,2,2,2]]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 200
#  -109 <= nums[i] <= 109
#  -109 <= target <= 109
#  
#  

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, n):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                component = target - nums[i] - nums[j]
                left = j + 1
                right = n - 1
                while left < right:
                    if nums[left] + nums[right] == component:
                        res.append([nums[i], nums[j], nums[left], nums[right]])
                        while left < right and nums[right] == nums[right - 1]:
                            right -= 1
                        while left < right and nums[left] == nums[left + 1]:
                            left += 1

                        left += 1
                        right -= 1
                    elif nums[left] + nums[right] > component:
                        right -= 1
                    else:
                        left += 1
        return res

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        n = len(nums)
        nums.sort()
        res = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, n):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                component = target - nums[i] - nums[j]
                history = {}
                k = j + 1
                while k < n:
                    if component - nums[k] in history:
                        res.append([nums[i], nums[j], nums[k], component - nums[k]])
                        while k + 1 < n and nums[k] == nums[k + 1]:
                            k += 1
                    else:
                        history[nums[k]] = k

                    k += 1
        return res

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        k = 4
        res = []
        nums.sort()

        if k > len(nums) or target < nums[0] * k or target > nums[-1] * k:
            return []

        self.kSum(nums, target, k, 0, [], res)
        return res

    def kSum(self, nums: List[int], target: int, k: int, start: int, ans: List[int], res: List[List]):
    
        if k == 2:
            self.twoSum(nums, target, k, start, ans, res)
            return

        for i in range(start, len(nums) - k + 1):
            if i > start and nums[i] == nums[i - 1]:
                continue
            
            ans.append(nums[i])
            self.kSum(nums, target, k - 1, i + 1, ans, res)
            ans.pop()

    def twoSum(self, nums: List[int], target: int, k: int, start: int, ans: List[int], res: List[List]):
        left = start
        right = len(nums) - 1

        while left < right:
            total = sum(ans) + nums[left] + nums[right]

            if total == target:
                ans.append(nums[left])
                ans.append(nums[right])
                res.append(ans.copy())
                ans.pop()
                ans.pop()

                while (left < right and nums[left] == nums[left + 1]):
                    left += 1
                while (left < right and nums[right] == nums[right - 1]):
                    right -= 1

                left += 1
                right -= 1
            elif total > target:
                right -= 1
            else:
                left += 1