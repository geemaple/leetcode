class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return []
        
        start = 0
        res = []
        
        for i in range(1, len(nums) + 1):
            if i == len(nums) or nums[i] - nums[i - 1] != 1:
                if start == i - 1:
                    res.append(str(nums[start]))
                else:
                    res.append(str(nums[start]) + '->' + str(nums[i - 1]))
                    
                start = i
                
        return res