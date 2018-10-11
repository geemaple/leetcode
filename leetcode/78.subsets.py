# backtracing
# O(N * 2^N); O(2^N) solusions muliply each need O(N) to construct a array result
class Solution(object):
    def subsets(self, nums):
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
            visted.append(nums[i])
            self.dfs(nums, visted, results, i + 1)
            visted.pop()

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
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = [[]]
        size = len(nums)
        for i in range(size):
            for j in range(len(results)):
                results.append(list(results[j]))
                results[-1].append(nums[i])

        return results