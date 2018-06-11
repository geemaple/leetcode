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

# DFS O(2^N)
class Solution_dfs(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """  
        return self.can_jump_from_position(0, nums)

    def can_jump_from_position(self, pos, nums):
        if pos == len(nums) - 1:
            return True

        furthest = min(len(nums), pos + nums[pos] + 1)
       
        for i in range(pos + 1, furthest):
            if self.can_jump_from_position(i, nums):
                return True 

        return False

# DP top_down O(N^2)
class Solution_dp_top_down(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """  

        table = [None for i in range(len(nums))]
        table[-1] == True
        return self.can_jump_from_position(0, nums, table)

    def can_jump_from_position(self, pos, nums, memo):

        if pos == len(nums) - 1:
            return True

        if memo[pos] != None:
            return memo[pos]

        furthest = min(len(nums), pos + nums[pos] + 1)
       
        for i in range(pos + 1, furthest):
            if self.can_jump_from_position(i, nums, memo):
                memo[pos] = True
                return True 

        memo[pos] = False
        return False

# DP bottom_up O(N^2)
class Solution_dp_bottom_up(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """  

        table = [None for i in range(len(nums))]
        table[-1] = True
   
        for i in range(len(nums) - 2, -1, -1):
            furthest = min(len(nums), i + nums[i] + 1)
            for j in range(i + 1, furthest):
                if table[j]:
                    table[i] = True
                    break

        return table[0] == True
