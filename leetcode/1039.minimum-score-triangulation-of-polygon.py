#  Tag: Array, Dynamic Programming
#  Time: O(N^3)
#  Space: O(N^2)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/rqaUgAK9G-E

#  You have a convex n-sided polygon where each vertex has an integer value. You are given an integer array values where values[i] is the value of the ith vertex in clockwise order.
#  Polygon triangulation is a process where you divide a polygon into a set of triangles and the vertices of each triangle must also be vertices of the original polygon. Note that no other shapes other than triangles are allowed in the division. This process will result in n - 2 triangles.
#  You will triangulate the polygon. For each triangle, the weight of that triangle is the product of the values at its vertices. The total score of the triangulation is the sum of these weights over all n - 2 triangles.
#  Return the minimum possible score that you can achieve with some triangulation of the polygon.
#   
#  Example 1:
#  
#  
#  Input: values = [1,2,3]
#  Output: 6
#  Explanation: The polygon is already triangulated, and the score of the only triangle is 6.
#  
#  Example 2:
#  
#  
#  Input: values = [3,7,4,5]
#  Output: 144
#  Explanation: There are two triangulations, with possible scores: 3*7*5 + 4*5*7 = 245, or 3*4*5 + 3*4*7 = 144.
#  The minimum score is 144.
#  
#  Example 3:
#  
#  
#  Input: values = [1,3,1,4,1,5]
#  Output: 13
#  Explanation: The minimum score triangulation is 1*1*3 + 1*1*4 + 1*1*5 + 1*1*1 = 13.
#  
#   
#  Constraints:
#  
#  n == values.length
#  3 <= n <= 50
#  1 <= values[i] <= 100
#  
#  

class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        dp = [[0] * n for _ in range(n)]
        
        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                dp[i][j] = float('inf')
                for k in range(i + 1, j):
                    area = dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]
                    dp[i][j] = min(dp[i][j], area)
        
        return dp[0][n - 1]
    
from functools import cache
class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        @cache
        def triangulate(l: int, r: int) -> int:
            if (r - l + 1) < 3:
                return 0

            res = float('inf')
            base = values[l] * values[r]
            for i in range(l + 1, r):
                score = base * values[i]
                left = triangulate(i, r)
                right = triangulate(l, i)
                res = min(res, score + left + right)

            return res

        return triangulate(0, len(values) - 1)