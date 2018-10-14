# f[i] = max(f[i - 1], f[i - 2] + A[i - 1])
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

        size = end - start + 1
        if size <= 0:
            return 0

        k = 2
        table = [0] * k
        table[0] = 0
        table[1] = nums[start]

        for i in range(2, size + 1):
            table[i % k] = max(table[(i - 2 + k) % k] + nums[start + i - 1], table[(i - 1 + k) % k])

        return table[size % k]