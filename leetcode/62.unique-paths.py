class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        table = [[0 for j in range(n)] for i in range(m)]

        table[0][0] = 1

        # the first row
        for j in range(1, n):
            table[0][j] = 1

        # the first column
        for i in range(1, m):
            table[i][0] = 1

        for i in range(1, m):
            for j in range(1, n):
                table[i][j] = table[i][j - 1] + table[i - 1][j]

        return table[-1][-1]
