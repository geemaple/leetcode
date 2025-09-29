#  Tag: Array, Math, Geometry
#  Time: O(N^3)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/KajV7to3Tlo

#  Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.
#   
#  Example 1:
#  
#  
#  Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
#  Output: 2.00000
#  Explanation: The five points are shown in the above figure. The red triangle is the largest.
#  
#  Example 2:
#  
#  Input: points = [[1,0],[0,0],[0,1]]
#  Output: 0.50000
#  
#   
#  Constraints:
#  
#  3 <= points.length <= 50
#  -50 <= xi, yi <= 50
#  All the given points are unique.
#  
#  

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        res = 0
        for a in points:
            for b in points:
                for c in points:
                    area = 0.5 * abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[0] * c[1] - c[0] * b[1] - b[0] * a[1])
                    res = max(res, area)

        return res