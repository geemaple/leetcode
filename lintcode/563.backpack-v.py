 # f[i][w] = f[i - 1][w] + f[i - 1][w - A[i - 1]]
class Solution:
    """
    @param nums: an integer array and all positive numbers
    @param target: An integer
    @return: An integer
    """
    def backPackV(self, nums, target):
        # write your code here
        table = [0 for _ in range(target + 1)]
        table[0] = 1

        for i in range(len(nums)):
            for w in range(target, -1, -1):
                value = table[w]
                if w - nums[i] >= 0:
                    value += table[w - nums[i]]
                    
                table[w] = value

        return table[-1]