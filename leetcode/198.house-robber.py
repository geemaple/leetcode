# if steal x: f(x) = min(f(x - 1) + nums[x])
# if not steal x: = min(f(x - 1))
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if nums is None or len(nums) == 0:
            return 0

        m = len(nums)
        table = [[0, 0] for _ in range(m + 1)]

        for i in range(1, m + 1):
            # steal
            table[i][1] = table[i - 1][0] + nums[i - 1]

            # not steal
            table[i][0] = max(table[i - 1][0], table[i - 1][1])

        return max(table[-1])