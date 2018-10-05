# f[i][j] = max(f[i][k] + f[k][j] + a[i] * a[k] * a[j]) where i < k < j
class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0

        balloons = [1 for _ in range(len(nums) + 2)]
        balloons[1:-1] = nums
        m = len(balloons)

        table = [[0 for _ in range(m)] for _ in range(m)]

        # length = 2
        for i in range(m - 1):
            table[i][i + 1] = 0

        for length in range(3, m + 1):
            for i in range(m - length + 1):
                j = i + length - 1
                for k in range(i + 1, j):
                    table[i][j] = max(table[i][j], table[i][k] + table[k][j] + balloons[i] * balloons[k] * balloons[j])

        return table[0][m - 1]


