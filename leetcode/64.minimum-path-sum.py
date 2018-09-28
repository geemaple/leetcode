# f(x) = min(num[x] + f(left), num[x] + f(top))
class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if grid is None or len(grid) == 0:
            return 0

        m = len(grid)
        n = len(grid[0])
        table = [[0 for _ in range(n)] for _ in range(m)]

        for j in range(n):
            table[0][j] = grid[0][j]
            if j - 1 >= 0:
                table[0][j] += table[0][j - 1]

        for i in range(1, m):
            for j in range(n):
                value = table[i - 1][j] + grid[i][j]

                if j - 1 >= 0:
                    value = min(value, table[i][j - 1] + grid[i][j])

                table[i][j] = value

        return table[-1][-1]
