# greedy
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        jumps = 0
        cur_end = 0
        cur_furthest = 0

        for i in range(len(nums) - 1):
            cur_furthest = max(cur_furthest, i + nums[i])
            if (i == cur_end):
                jumps += 1
                cur_end = cur_furthest
        
        return jumps

# DP O(N^2) Time Limit Exceeded
class Solution2(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        table = [0 for i in range(len(nums))]
        table[0] = 0

        for i in range(1, len(nums)):
            jump_count = float('inf')
            for j in range(0, i):
                if nums[j] >= i - j:
                    jump_count = min(jump_count, table[j] + 1)
            table[i] = jump_count
    
        return table[-1]