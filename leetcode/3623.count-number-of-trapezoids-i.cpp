//  Tag: Array, Hash Table, Math, Geometry
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
//  A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.
//  Return the  number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
//  Output: 3
//  Explanation:
//    
//  There are three distinct ways to pick four points that form a horizontal trapezoid:
//  
//  Using points [1,0], [2,0], [3,2], and [2,2].
//  Using points [2,0], [3,0], [3,2], and [2,2].
//  Using points [1,0], [3,0], [3,2], and [2,2].
//  
//  
//  Example 2:
//  
//  Input: points = [[0,0],[1,0],[0,1],[2,1]]
//  Output: 1
//  Explanation:
//  
//  There is only one horizontal trapezoid that can be formed.
//  
//   
//  Constraints:
//  
//  4 <= points.length <= 105
//  –108 <= xi, yi <= 108
//  All points are pairwise distinct.
//  
//  

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int mod = 1e9 + 7;
        unordered_map<int, int> group;
        for (auto &x: points) {
            group[x[1]] += 1;
        }
        int res = 0;
        int total = 0;
        for (auto &[y, count]: group) {
            long long lines = count * (count - 1LL) / 2;
            res = (res + total * lines) % mod;
            total = (total + lines) % mod;
        }

        return res;
    }
};