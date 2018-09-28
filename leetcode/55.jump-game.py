# greedy O(N)
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        last_pos = len(nums) - 1
        for i in range(last_pos, -1, -1):
            if i + nums[i] >= last_pos:
                last_pos = i
        
        return last_pos == 0

# DP
# table[i] = or (table[pre] >= i - pre)
# O(N ^ 2) Time Limit Exceeded
class Solution2(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        table = [False] * len(nums)
        table[0] = True

        for i in range(len(nums)):
            for j in range(i):
                if table[j] and nums[j] >= i - j:
                    table[i] = True
                    break

        return table[-1]

# DFS O(2^N) Time Limit Exceeded
# [3, 2, 1, 0 ,4]
class Solution3(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """  
        return self.can_jump_from_position(0, nums)

    def can_jump_from_position(self, pos, nums):
        if pos == len(nums) - 1:
            return True

        furthest = min(len(nums) - 1, pos + nums[pos])
       
        for i in range(pos + 1, furthest + 1):
            if self.can_jump_from_position(i, nums):
                return True 

        return False