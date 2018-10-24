# x(row), y(column)
# (0, 0)
# (1, 0), (1, 1)
# (2, 0), (2, 1), (2, 2)
# (3, 0), (3, 1), (3, 2), (3, 3)

# DP bottom-up O(N^2)
# f[i][j] = min(f[i + 1][j], f[i + 1][i + 1]) + triangle[i][j]
class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        if len(triangle) == 0 or len(triangle[0]) == 0:
            return 0
        
        size = len(triangle)
        table = triangle[-1][:]
        
        for i in range(size - 2, -1, -1):
            for j in range(len(triangle[i])):
                table[j] = min(table[j], table[j + 1]) + triangle[i][j]
                
        return table[0]
        

# DP top-down O(N^2)
class SolutionDP_top_down(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        table = [[0 for j in range(len(triangle[i]))] for i in range(len(triangle))]

        for i in range(len(triangle)):
            for j in range(i + 1):
                
                table[i][j] = triangle[i][j]
                if i - 1 >= 0:
                    tmp = float('inf')

                    if j - 1 >= 0:
                        tmp = table[i - 1][j - 1]

                    if j < i:
                        tmp = min(tmp, table[i - 1][j])

                    table[i][j] += tmp
        return min(table[-1])

# divideAndConquer + memory O(N^2) since (x, y), x, y each has N possible numbers
class SolutionDFS_M(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        memroy = {}
        return self.divideAndConquer(triangle, memroy, 0, 0)

    def divideAndConquer(self, triangle, mem, x, y):
        if x >= len(triangle):
            return 0

        if (x, y) in mem:
            return mem[(x, y)]

        result = triangle[x][y] + min(
            self.divideAndConquer(triangle, mem, x + 1, y),
            self.divideAndConquer(triangle, mem, x + 1, y + 1),
        )

        mem[(x, y)] = result

        return result


# DFS O(2^N)
class SolutionDC(object):

    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        return self.divideAndConquer(triangle, 0, 0)

    def divideAndConquer(self, triangle, x, y):
        if x >= len(triangle):
            return 0

        return triangle[x][y] + min(
            self.divideAndConquer(triangle, x + 1, y),
            self.divideAndConquer(triangle, x + 1, y + 1),
        )

# DFS O(2^N)
class SolutionDFS(object):

    min_sum = float('inf')
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        tmp = []
        self.dfs(triangle, tmp, 0, 0)
        return self.min_sum

    def dfs(self, triangle, tmp, x, y):
        if x >= len(triangle):
            result = sum(tmp)
            if result < self.min_sum:
                self.min_sum = result
            return

        tmp.append(triangle[x][y])
        self.dfs(triangle, tmp, x + 1, y)
        self.dfs(triangle, tmp, x + 1, y + 1)
        tmp.pop()