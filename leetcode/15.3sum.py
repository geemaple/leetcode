class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        nums.sort()

        for i in range(len(nums) - 2):
            
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            
            a = nums[i]
            left = i + 1
            right = len(nums) - 1
            
            while left < right: # two sum

                if nums[left] + nums[right] == -a:
                    res.append([a, nums[left], nums[right]])
                    
                    while (left < right and nums[left] == nums[left + 1]):
                        left += 1
                          
                    while (left < right and nums[right] == nums[right - 1]):
                        right -= 1

                    left += 1
                    right -= 1
                elif nums[left] + nums[right] > -a:
                    right -= 1
                else:
                    left += 1
                    
        return res