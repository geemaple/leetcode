class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        visted = set()
        tmp = []
        results = []
        sorted_nums = sorted(nums)
        self.helper(sorted_nums, visted, tmp, results)
        return results

    def helper(self, nums, visted, tmp, results):
        if len(tmp) == len(nums):
            results.append(list(tmp))
            return

        for i in range(len(nums)):
            if i in visted:
                continue

            if i > 0 and nums[i] == nums[i - 1] and i - 1 not in visted:
                continue

            visted.add(i)

            tmp.append(nums[i])
            self.helper(nums, visted, tmp, results)
            tmp.pop()

            visted.remove(i)