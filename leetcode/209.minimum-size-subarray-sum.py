class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
            :type s: int
            :type nums: List[int]
            :rtype: int
            """
        
        j = 0
        res = float('inf')
        sums = 0
        
        for i in range(len(nums)):
            while (j < len(nums) and sums < s):
                sums += nums[j]
                j += 1
            
            if (sums >= s):
                res = min(res, j - i)
            
            sums -= nums[i]
        
        return 0 if res == float('inf') else res
