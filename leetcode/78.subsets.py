#
# [78] Subsets
#
# https://leetcode.com/problems/subsets/description/
#
# algorithms
# Medium (47.99%)
# Total Accepted:    282.2K
# Total Submissions: 587.3K
# Testcase Example:  '[1,2,3]'
#
# Given a set of distinct integers, nums, return all possible subsets (the
# power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: nums = [1,2,3]
# Output:
# [
# ⁠ [3],
# [1],
# [2],
# [1,2,3],
# [1,3],
# [2,3],
# [1,2],
# []
# ]
# 
#

# backtracing
# O(N * 2^N); O(2^N) solusions multiply each need O(N) to construct a array result
# 20 ms, faster than 71.68%
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        tmp = []
        self.helper(sorted(nums), tmp, 0, results)
        return results

    def helper(self, nums, tmp, start, results):
        results.append(tmp[:]) # another copy results.append(list(tmp))

        for i in range(start, len(nums)):
            tmp.append(nums[i])
            self.helper(nums, tmp, i + 1, results)
            tmp.pop()

# bit manipulation
# O(N * 2^N)

# suppose [1, 2, 3] initially the 8 subsets are all empty
# a way to visualize this idea. That is,
# 1 appears once in every two consecutive subsets,
# 2 appears twice in every four consecutive subsets,
# 3 appears four times in every eight subsets, shown in the following:
# [], [], [], [], [], [], [], []

# [], [1], [], [1], [], [1], [], [1]

# [], [1], [2], [1, 2], [], [1], [2], [1, 2]

# [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
class Solution2(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        size = len(nums)
        num_subset = 2 ** size
        results = [[] for _ in range(num_subset)]

        for i in range(size):
            for j in range(num_subset):
                if ((j >> i) & 1):
                    results[j].append(nums[i])

        return results


# iterative
# 2^0 + 2^1 + ... + 2^N = O(2^N) * O(N)
# suppose [1, 2, 3] initially and the results = [[]]
# copy every item and append nums[i] to new copy one
# for 1 [[], [1]]
# for 2 [[], [1], [2], [1, 2]]
# for 3 [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]] 
#
# 24 ms, faster than 39.46%
class Solution3(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = [[]]
        size = len(nums)
        for i in range(size):
            for j in range(len(results)):
                tmp = results[j] + [nums[i]]
                results.append(tmp)

        return results