# f[i][j] = f[i - 1][j - 1] where s[i - 1] == p[j - 1] || p[j - 1] == '.' case p[j - 1] != '*'
# f[i][j] = f[i][j - 2] or f[i - 1][j] where s[i - 1] == p[j - 2] || p[j - 2] == '.' case p[j - 1] == '*'


class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        m = len(s)
        n = len(p)
        table = [[False for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    table[i][j] = True
                    continue

                if j == 0:
                    table[i][j] = False
                    continue

                if p[j - 1] != '*':
                    if i - 1 >= 0 and (p[j - 1] == '.' or p[j - 1] == s[i- 1]):
                        table[i][j] = table[i - 1][j - 1]
                else:
                    if j - 2 >= 0:
                        table[i][j] = table[i][j - 2]

                        if i - 1 >= 0 and (p[j - 2] == '.' or p[j - 2] == s[i - 1]):
                            table[i][j] = table[i][j] or table[i - 1][j]

        return table[m][n]