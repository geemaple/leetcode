//  Tag: Array, Hash Table, Math, Geometry
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: TBD

//  You are given a 2D integer array points where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
//  Return the number of unique trapezoids that can be formed by choosing any four distinct points from points.
//  A trapezoid is a convex quadrilateral with at least one pair of parallel sides. Two lines are parallel if and only if they have the same slope.
//   
//  Example 1:
//  
//  Input: points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]]
//  Output: 2
//  Explanation:
//   
//  There are two distinct ways to pick four points that form a trapezoid:
//  
//  The points [-3,2], [2,3], [3,2], [2,-3] form one trapezoid.
//  The points [2,3], [3,2], [3,0], [2,-3] form another trapezoid.
//  
//  
//  Example 2:
//  
//  Input: points = [[0,0],[1,0],[0,1],[2,1]]
//  Output: 1
//  Explanation:
//  
//  There is only one trapezoid which can be formed.
//  
//   
//  Constraints:
//  
//  4 <= points.length <= 500
//  –1000 <= xi, yi <= 1000
//  All points are pairwise distinct.
//  
//  

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, unordered_map<int, int>> t, v;

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {

                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx < 0 || (dx == 0 && dy < 0))
                    dx = -dx, dy = -dy;

                int g = gcd(dx, abs(dy));

                int sx = dx / g;
                int sy = dy / g;

                int des = sx * points[i][1] - sy * points[i][0];

                int key1 = (sx << 12) | (sy + 2000);
                int key2 = (dx << 12) | (dy + 2000);

                ++t[key1][des];
                ++v[key2][des];
            }
        }

        return count(t) - count(v) / 2;
    }

    int count(unordered_map<int, unordered_map<int, int>>& mp) {
        long long ans = 0;

        for (auto& [k1, inner] : mp) {
            long long sum = 0;
            for (auto& [k2, val] : inner)
                sum += val;

            for (auto& [k2, val] : inner)
                ans += val * (sum -= val);
        }

        return ans;
    }
};