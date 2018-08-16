class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        if nums is None:
            return 0

        nums.sort()
        start = 0
        ans = 0

        while start < len(nums):
            end = start + 1

            while(end < len(nums) and nums[end] - nums[start] < k):
                end += 1

            if (end < len(nums) and nums[end] - nums[start] == k):
                ans += 1

                #remove duplicate
                while(start + 1 < len(nums) and nums[start + 1] == nums[start]):
                    start += 1

            start += 1

        return ans
