#  Tag: Array, Hash Table, Math, Geometry
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: TBD

#  You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
#  Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
#  A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.
#   
#  Example 1:
#  
#  Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
#  Output: 2
#  Explanation:
#   
#  There are two distinct ways to pick four points that form a trapezoid:
#  
#  The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
#  The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
#  
#  
#  Example 2:
#  
#  Input: points = [[0,0],[1,0],[0,1],[2,1]]
#  Output: 1
#  Explanation:
#  
#  There is only one trapezoid which can be formed.
#  
#   
#  Constraints:
#  
#  4 <= points.length <= 500
#  –1000 <= xi, yi <= 1000
#  All points are pairwise distinct.
#  
#  

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        slopes, lines, mids, midlines = [Counter() for _ in range(4)]
        ans = 0
        for (x1, y1), (x2, y2) in combinations(points, 2):
            dx, dy = x2 - x1, y2 - y1
            k = dy / dx if dx else float('inf')
            b = (y1 * dx - x1 * dy) / dx if dx else x1

            ans += slopes[k] - lines[k, b]
            # Parallelgram Count Twice，Diagonal Intersects at the Same Point
            ans -= mids[x1 + x2, y1 + y2] - midlines[x1 + x2, y1 + y2, k] 
            slopes[k] += 1
            lines[k, b] += 1
            mids[x1 + x2, y1 + y2] += 1
            midlines[x1 + x2, y1 + y2, k] += 1
        return ans