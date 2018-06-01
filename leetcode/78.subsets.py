class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        visted = []
        sorted_nums = sorted(nums)
        self.helper(sorted_nums, visted, results, 0)
        return results

    def helper(self, nums, visted, results, start):

        results.append(list(visted))

        for i in range(start, len(nums)):
            visted.append(nums[i])
            self.helper(nums, visted, results, i + 1)
            visted.pop()