# f[i] = f[i - A1] + f[i - A2] ... + f[i - A(n-1)]
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        table = [0 for _ in range(target + 1)]
        table[0] = 1

        for i in range(1, target + 1):
            count = 0

            for j in range(len(nums)):
                if i - nums[j] >= 0:
                    count += table[i - nums[j]]

            table[i] = count

        return table[-1]