class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        res = float('inf')
        nums.sort()

        for i in range(len(nums) - 2):            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right:
                threeSum = a + nums[left] + nums[right]
                if abs(threeSum - target) < abs(res - target):
                    res = threeSum
                    
                if threeSum == target:
                    break
                elif threeSum > target:
                    right -= 1
                else:
                    left += 1
                    
        return res


class Solution2:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closest = float('inf')
        nums.sort()

        for i in range(len(nums) - 2):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right:

                threeSum = a + nums[left] + nums[right]
                
                if abs(threeSum - target) < abs(closest - target):
                    closest = threeSum
                    
                if threeSum == target:
                    break
                elif threeSum > target:
                    while (left < right and nums[right] == nums[right - 1]): #remove duplicate
                      right -= 1
                    right -= 1
                else:
                    while (left < right and nums[left] == nums[left + 1]): #remove duplicate
                      left += 1
                    left += 1
                    
        return closest