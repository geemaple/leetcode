# f[i][j] = max(f[i - 1][j], f[i][j - 1]) where s[i] != s[j])
# f[i][j] = f[i + 1][j - 1] + 2) where s[i] == s[j]

class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        m = len(s)
        table = [[-1 for _ in range(m)] for _ in range(m)]

        # length = 1
        for i in range(m):
            table[i][i] = 1

        # length = 2
        for i in range(m  - 1):
            table[i][i + 1] = 2 if s[i] == s[i + 1] else 1

        for length in range(3, m + 1):
            for i in range(0, m - length + 1):
                j = i + length - 1
                
                if s[i] == s[j]:
                    table[i][j] = table[i + 1][j - 1] + 2
                else:
                    table[i][j] = max(table[i + 1][j], table[i][j - 1])

        return table[0][-1]
