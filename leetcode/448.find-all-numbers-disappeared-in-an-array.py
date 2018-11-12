class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        for i in nums:
            idx = abs(i) - 1
            nums[idx] = -1 * abs(nums[idx])
            
        res = []
        for i in xrange(len(nums)):
            if nums[i] > 0:
                res.append(i + 1)

        return res