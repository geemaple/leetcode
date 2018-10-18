class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mask = 0
        for n in nums:
            mask ^= n
        return mask
        