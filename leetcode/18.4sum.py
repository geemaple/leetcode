from typing import List
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        for i in range(len(nums) - 3):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            a = nums[i]
            
            for j in range(i + 1, len(nums) - 2): # 3sum
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                b = nums[j]
                left = j + 1
                right = len(nums) - 1
                
                while left < right: # two sum

                    if a + b + nums[left] + nums[right] == target:
                        res.append([a, b, nums[left], nums[right]])
                        
                        while (left < right and nums[left] == nums[left + 1]):
                            left += 1
                            
                        while (left < right and nums[right] == nums[right - 1]):
                            right -= 1

                        left += 1
                        right -= 1
                    elif a + b + nums[left] + nums[right] > target:
                        right -= 1
                    else:
                        left += 1
                    
        return res

class Solution2:
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