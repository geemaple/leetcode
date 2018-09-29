class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if nums is None or len(nums) == 0:
            return 0

        return max(self.rob_house(nums, 1, len(nums) - 1), self.rob_house(nums, 2, len(nums) - 2) + nums[0])
        
    def rob_house(self, nums, start, end):
        if end - start + 1 <= 0:
            return 0

        m = end - start + 1
        table = [0] * (m + 1)
        table[1] = nums[start]

        for i in range(2, m + 1):
            table[i] = max(table[i - 2] + nums[start + i - 1], table[i - 1])

        return table[-1]