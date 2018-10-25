# Your runtime beats 42.1 % of python submissions
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        results = []
        if len(nums) < 4:
            return results
        
        nums.sort()
        res = []
        
        for i in range(len(nums)):
            
            if i != 0 and nums[i] == nums[i - 1]:
                continue
            
            for j in range(i + 1, len(nums)):
                
                if j != i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                self.twoSum(nums, i, j, target, res)
                
        return res
        
    def twoSum(self,nums, i, j, target, results):
        
        start = j + 1
        end = len(nums) - 1
        
        while(start < end):
            tmp = nums[i] + nums[j] + nums[start] + nums[end]
            if tmp == target:
                results.append((nums[i], nums[j], nums[start], nums[end]))
                
                while start < end and nums[start] == nums[start + 1]:
                    start += 1
                    
                while start < end and nums[end] == nums[end - 1]:
                    end -= 1
                    
                start += 1
                end -= 1
                
            elif tmp > target:
                end -= 1
            else:
                start += 1