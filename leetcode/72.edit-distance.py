# f[i][j] = min(f[i - 1][j] + 1, f[i - 1][j - 1] + 1, f[i][j - 1] + 1, f[i - 1][j - 1] where s1[i - 1] == s2[j - 1])
class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        m = len(word1)
        n = len(word2)

        table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 or j == 0:
                    table[i][j] = abs(i - j)
                else:
                    if word1[i - 1] == word2[j - 1]:
                        table[i][j] = table[i - 1][j - 1]
                    else:
                        value = min(table[i - 1][j] + 1, table[i][j - 1] + 1)
                        value = min(value, table[i - 1][j - 1] + 1)
                        table[i][j] = value

        return table[m][n]
