# DP O(N^2)
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if nums is None or len(nums) == 0:
            return 0

        table = [i for i in range(len(nums))]
        table[0] = 1

        for i in range(1, len(nums)):
            biggest = 0
            for j in range(i):
                if nums[j] < nums[i]:
                    biggest = max(biggest, table[j])
            table[i] = biggest + 1

        return max(table)