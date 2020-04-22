#
# [90] Subsets II
#
# https://leetcode.com/problems/subsets-ii/description/
#
# algorithms
# Medium (39.90%)
# Total Accepted:    168.4K
# Total Submissions: 421.6K
# Testcase Example:  '[1,2,2]'
#
# Given a collection of integers that might contain duplicates, nums, return
# all possible subsets (the power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: [1,2,2]
# Output:
# [
# ⁠ [2],
# ⁠ [1],
# ⁠ [1,2,2],
# ⁠ [2,2],
# ⁠ [1,2],
# ⁠ []
# ]
# 
# 
#

# refer to 78.subset
# 24 ms, faster than 72.15%
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        tmp = []
        self.helper(sorted(nums), tmp, 0, results)
        return results

    def helper(self, nums, tmp, start, results):
        results.append(tmp[:])

        for i in range(start, len(nums)):
            if i > start and nums[i] == nums[i - 1]:
                continue
            else:
                tmp.append(nums[i])
                self.helper(nums, tmp, i + 1, results)
                tmp.pop()

# refer to 78.subset
# 28 ms, faster than 42.58%
class Solution3(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = [[]]
        size = len(nums)
        sort_nums = sorted(nums)
        for i in range(size):
            if i == 0 or sort_nums[i] != sort_nums[i - 1]:
                l = len(results)
            
            for j in range(len(results) - l, len(results)):
                tmp = results[j] + [sort_nums[i]]
                results.append(tmp)