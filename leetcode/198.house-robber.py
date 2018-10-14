# f[i] = max(f[i - 1], f[i - 2] + A[i - 1])
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if nums is None or len(nums) == 0:
            return 0
        
        size = len(nums)
        k = 2
        table = [0 for _ in range(k)]
        table[0] = 0
        table[1] = nums[0]
        
        for i in range(2, size + 1):
            table[i % k] = max(table[(i - 1 + k) % k], table[(i - 2 + k) % k] + nums[i - 1])
            
        return table[size % k]