# if grid[x] = 'E': f(x) = f(up) + 1
# if grid[x] = 'W': f(x) = 0
# if grid[x] = '0': f(x) = f(up)

class Solution(object):
    def maxKilledEnemies(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        if grid is None or len(grid) == 0:
            return 0

        m = len(grid)
        n = len(grid[0])

        direction = [[0 for _ in range(n)] for _ in range(m)]
        table = [[0 for _ in range(n)] for _ in range(m)]

        # up
        for i in range(m):
            for j in range(n):
                if i == 0:
                    direction[0][j] = 1 if grid[0][j] == 'E' else 0
                else:
                    if grid[i][j] == 'E':
                        direction[i][j] = direction[i - 1][j] + 1
                    elif grid[i][j] == '0':
                        direction[i][j] = direction[i - 1][j]
                    else:
                        direction[i][j] = 0

                table[i][j] += direction[i][j]

        # left
        for i in range(m):
            for j in range(n):
                if j == 0:
                    direction[i][0] = 1 if grid[i][0] == 'E' else 0
                else:
                    if grid[i][j] == 'E':
                        direction[i][j] = direction[i][j - 1] + 1
                    elif grid[i][j] == '0':
                        direction[i][j] = direction[i][j - 1]
                    else:
                        direction[i][j] = 0

                table[i][j] += direction[i][j]

        # bottom
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1:
                    direction[m - 1][j] = 1 if grid[m - 1][j] == 'E' else 0
                else:
                    if grid[i][j] == 'E':
                        direction[i][j] = direction[i + 1][j] + 1
                    elif grid[i][j] == '0':
                        direction[i][j] = direction[i + 1][j]
                    else:
                        direction[i][j] = 0

                table[i][j] += direction[i][j]

        # right
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if j == n - 1:
                    direction[i][n - 1] = 1 if grid[i][n - 1] == 'E' else 0
                else:
                    if grid[i][j] == 'E':
                        direction[i][j] = direction[i][j + 1] + 1
                    elif grid[i][j] == '0':
                        direction[i][j] = direction[i][j + 1]
                    else:
                        direction[i][j] = 0

                table[i][j] += direction[i][j]

        res = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '0':
                    res = max(res, table[i][j])

        return res
        