# f(i) = max(1, table[j] + 1 if nums[i] > nums[j])
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        size = len(nums)
        table = [0] * size 
        table[0] = 1

        for i in range(1, size):
            value = 1

            for j in range(i):
                if nums[i] > nums[j]:
                    value = max(value, table[j] + 1)

            table[i] = value

        return max(table)