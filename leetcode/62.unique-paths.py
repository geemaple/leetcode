# f(target) = f(left) + f(top)
class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        table = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if i == 0 or j == 0:
                    table[i][j] = 1
                else:
                    table[i][j] = table[i - 1][j] + table[i][j - 1]

        return table[-1][-1]
