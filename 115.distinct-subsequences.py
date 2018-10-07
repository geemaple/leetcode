# f[i][j] = f[i - 1][j] + f[i - 1][j - 1] where s[i - 1] == t[j - 1]
class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        m = len(s)
        n = len(t)

        table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    table[i][j] = 1 if j == 0 else 0
                else:
                    table[i][j] = table[i - 1][j]

                    if s[i - 1] == t[j - 1]:
                        table[i][j] += table[i - 1][j - 1]

        return table[m][n]
