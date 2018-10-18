class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        res = 1
        i = 0
        for j in range(1, len(nums)):
            if nums[j] <= nums[j - 1]:
                i = j
            
            res = max(res, j - i + 1)
                
        return res