class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        
        if obstacleGrid is None or len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0:
            return 0

        row = len(obstacleGrid)
        column = len(obstacleGrid[0])

        table = [[0 for j in range(column)] for i in range(row)]

        table[0][0] = 1 if obstacleGrid[0][0] == 0 else 0

        # the first row
        for j in range(1, column):
            if obstacleGrid[0][j] == 0:
                table[0][j] = 1 if table[0][j - 1] != 0 else 0
            else:
                table[0][j] = 0

        # the first column
        for i in range(1, row):
            if obstacleGrid[i][0] == 0:
                table[i][0] = 1 if table[i - 1][0] != 0 else 0 
            else:
                table[i][0] = 0

        for i in range(1, row):
            for j in range(1, column):
                if obstacleGrid[i][j] == 0:
                    table[i][j] = table[i][j - 1] + table[i - 1][j]
                else:
                    table[i][j] = 0

        return table[-1][-1]
                

        
