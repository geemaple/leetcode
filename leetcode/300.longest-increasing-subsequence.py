# O(N * logN)
# https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = []
        for n in nums:
            index = self.binary_search(res, n) # use bisect.bisect_left to reduce more runtime
            if index == -1:
                res.append(n)
            else:
                res[index] = n

        return len(res)

    def binary_search(self, nums, target):
        #find element no less than target

        if len(nums) == 0:
            return -1

        start = 0
        end = len(nums) - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2
            if nums[mid] < target:
                start = mid
            else:
                end = mid

        if nums[start] >= target:
            return start

        if nums[end] >= target:
            return end

        return -1


# f(i) = max(1, f(j) + 1 if j < i and nums[j] < nums[i])
# O(N ^ 2)
class Solution2(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        m = len(nums)
        table = [0 for _ in range(m)]
        table[0] = 1

        for i in range(1, m):
            value = 1

            for j in range(i):
                if nums[j] < nums[i]:
                    value = max(value, table[j] + 1)

            table[i] = value

        return max(table)
