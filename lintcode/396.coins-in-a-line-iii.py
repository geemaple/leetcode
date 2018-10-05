# f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1])
class Solution:
    """
    @param values: a vector of integers
    @return: a boolean which equals to true if the first player will win
    """
    def firstWillWin(self, values):
        # write your code here
        if values is None or len(values) == 0:
            return 0

        m = len(values)
        table = [[0 for _ in range(m)] for _ in range(m)]

        # length = 1
        for i in range(m):
            table[i][i] = values[i]

        for length in range(2, m + 1):
            for i in range(0, m - length + 1):
                j = i + length - 1
                table[i][j] = max(values[i] - table[i + 1][j], values[j] - table[i][j - 1])

        return table[0][m - 1] >= 0