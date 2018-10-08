# f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - count0[i - 1]][k - count1[i - 1]] + 1)
class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        
        size = len(strs)
        count1 = [0 for _ in range(size)]
        count0 = [0 for _ in range(size)]

        for i in range(size):
            for j in range(len(strs[i])):

                if strs[i][j] == '1':
                    count1[i] += 1
                else:
                    count0[i] += 1

        table = [[[0 for _ in range(n + 1)] for _ in range(m + 1)] for _ in range(size + 1)]

        for i in range(1, size + 1):
            for j in range(m + 1):
                for k in range(n + 1):
                    table[i][j][k] = table[i - 1][j][k]
                    if j - count0[i - 1] >= 0 and k - count1[i - 1] >= 0:
                        table[i][j][k] = max(table[i][j][k], table[i - 1][j - count0[i - 1]][k - count1[i - 1]] + 1)

        return table[-1][m][n]