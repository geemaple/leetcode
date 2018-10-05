# s1 start from i len = k
# s2 start from j len = k
# f[i][j][k] = max(f[i][j][w] and f[i + w][j + w][k - w]) where 1 <= w <= k - 1
#            = or max(f[i][j + k - w][w] and f[i + w][j][k - w]) where 1 <= w <= k - 1
class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        
        if len(s1) != len(s2):
            return False

        m = len(s1)
        table = [[[False for _ in range(m + 1)] for _ in range(m)] for _ in range(m)]

        # length = 1
        for i in range(m):
            for j in range(m):
                table[i][j][1] = (s1[i] == s2[j])

        for k in range(2, m + 1):
            for i in range(m - k + 1):
                for j in range(m - k + 1):
                    for w in range(1, k - 1 + 1):
                        
                        if (table[i][j][w] and table[i + w][j + w][k - w]):
                            table[i][j][k] = True
                            break

                        if (table[i][j + k - w][w] and table[i + w][j][k - w]):
                            table[i][j][k] = True
                            break

        return table[0][0][m]