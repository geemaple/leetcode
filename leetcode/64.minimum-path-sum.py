class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        
        if grid is None or len(grid) == 0 or len(grid[0]) == 0:
            return 0

        row = len(grid)
        column = len(grid[0])

        table = [[0 for j in range(column)] for i in range(row)]

        table[0][0] = grid[0][0]

        # the 1st row
        for j in range(1, column):
            table[0][j] = table[0][j - 1] + grid[0][j]

        # the 1st column
        for i in range(1, row):
            table[i][0] = table[i - 1][0] + grid[i][0]

        for i in range(1, row):
            for j in range(1, column):
                table[i][j] = min(table[i - 1][j], table[i][j - 1]) + grid[i][j]

        return table[-1][-1]