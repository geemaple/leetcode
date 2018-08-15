class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        if nums is None:
            return 0

        res = float('inf')
        sums = 0
        start = 0
        for end in range(len(nums)):
            sums += nums[end]

            while (sums >= s):
                res = min(res, end - start + 1)
                sums -= nums[start]
                start += 1

        return res if res != float('inf') else 0
