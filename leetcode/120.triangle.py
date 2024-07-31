#  Tag: Array, Dynamic Programming
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a triangle array, return the minimum path sum from top to bottom.
#  For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
#   
#  Example 1:
#  
#  Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
#  Output: 11
#  Explanation: The triangle looks like:
#     2
#    3 4
#   6 5 7
#  4 1 8 3
#  The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
#  
#  Example 2:
#  
#  Input: triangle = [[-10]]
#  Output: -10
#  
#   
#  Constraints:
#  
#  1 <= triangle.length <= 200
#  triangle[0].length == 1
#  triangle[i].length == triangle[i - 1].length + 1
#  -104 <= triangle[i][j] <= 104
#  
#   
#  Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?

class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        dp = triangle[-1].copy()

        for i in reversed(range(n - 1)):
            for j in range(len(triangle[i])):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])

        return dp[0]
        
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
