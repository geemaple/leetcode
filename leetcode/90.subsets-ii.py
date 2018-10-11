class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        visted = []
        sorted_nums = sorted(nums)
        self.dfs(sorted_nums, visted, results, 0)
        return results
        
    def dfs(self, nums, visted, results, start):

        results.append(list(visted))

        for i in range(start, len(nums)):
            
            if i > start and nums[i] == nums[i - 1]:
                continue

            visted.append(nums[i])
            self.dfs(nums, visted, results, i + 1)
            visted.pop()
