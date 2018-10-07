# f[i][j] = (f[i - 1][j] && s1[i - 1] == s3[i + j - 1]) or (f[i][j - 1] && s2[j - 1] == s3[i + j - 1])
class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1) + len(s2) != len(s3):
            return False

        m = len(s1)
        n = len(s2)

        table = [[False for _ in range(n + 1)] for _ in range(m + 1)]

        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0 and j == 0:
                    table[i][j] = True
                else:
                    if i > 0 and (table[i - 1][j] and s1[i - 1] == s3[i + j - 1]):
                        table[i][j] = True

                    
                    if j > 0 and (table[i][j - 1] and s2[j - 1] == s3[i + j - 1]):
                        table[i][j] = True

        return table[m][n]