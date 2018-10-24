class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        table = {}
        
        for i in range(len(nums)):
            
            if nums[i] in table:
                return [table[nums[i]], i]
            
            table[target - nums[i]] = i