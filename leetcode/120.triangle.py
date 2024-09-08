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
        m = len(triangle[-1])

        dp = list(triangle[-1])
        for i in range(n - 2, -1, -1):
            for j in range(len(triangle[i])):
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j]

        return dp[0]
        
# DP top-down O(N^2)
class Solution(object):
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        m = len(triangle[-1])

        dp = [0 for i in range(m)]
        dp[0] = triangle[0][0]

        for i in range(1, n):
            for j in range(len(triangle[i]) - 1, -1, -1):
                if j == 0:
                    dp[j] = dp[j] + triangle[i][j]
                elif j == len(triangle[i]) - 1:
                    dp[j] = dp[j - 1] + triangle[i][j]
                else:
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j]
                      
        return min(dp)

# divideAndConquer + memory O(N^2) since (x, y), x, y each has N possible numbers
class Solution(object):
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        memory = {}
        return self.helper(triangle, 0, 0, memory)

    def helper(self, triangle, i, j, memory):
        if i == len(triangle):
            return 0

        if (i, j) not in memory:
            left = self.helper(triangle, i + 1, j, memory)
            right = self.helper(triangle, i + 1, j + 1, memory)
            memory[(i, j)] = triangle[i][j] + min(left, right)

        return memory[(i, j)]


# DFS O(2^N)
class Solution(object):
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        return self.helper(triangle, 0, 0)

    def helper(self, triangle, i, j):
        if i == len(triangle):
            return 0

        left = self.helper(triangle, i + 1, j)
        right = self.helper(triangle, i + 1, j + 1)
        return triangle[i][j] + min(left, right)

# DFS O(2^N)
class Solution(object):
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        self.min_sum = float('inf')
        tmp = []
        self.helper(triangle, tmp, 0, 0)
        return self.min_sum

    def helper(self, triangle, tmp, i, j):
        if i == len(triangle):
            self.min_sum = min(self.min_sum, sum(tmp))
            return

        tmp.append(triangle[i][j])
        self.helper(triangle, tmp, i + 1, j)
        self.helper(triangle, tmp, i + 1, j + 1)
        tmp.pop()
