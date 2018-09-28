# f(x) = f(left) + f(top)
# if obstacleGrid(left) == 1: f(left) = 0
# if obstacleGrid(top) == 1: f(top) = 0
class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        
        if obstacleGrid is None or len(obstacleGrid) == 0 or len(obstacleGrid[0]) == 0:
            return 1

        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        table = [[0 for _ in range(n)] for _ in range(m)]

        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    table[i][j] == 0
                    continue

                if (i == 0 and j == 0):
                    table[i][j] = 1 - obstacleGrid[i][j]
                else:
                    if i - 1 >= 0:
                        table[i][j] += table[i - 1][j]
                    if j - 1 >= 0:
                        table[i][j] += table[i][j - 1]

        return table[-1][-1]                