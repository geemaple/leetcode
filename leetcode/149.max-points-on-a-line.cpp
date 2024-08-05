//  Tag: Array, Hash Table, Math, Geometry
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: 

//  Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
//   
//  Example 1:
//  
//  
//  Input: points = [[1,1],[2,2],[3,3]]
//  Output: 3
//  
//  Example 2:
//  
//  
//  Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= points.length <= 300
//  points[i].length == 2
//  -104 <= xi, yi <= 104
//  All the points are unique.
//  
//  

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> count;
            int sameX = 0;
            for (int j = i + 1; j < n; j++) {
                if (points[i][0] == points[j][0]) {
                    sameX += 1;
                } else {
                    // 如果精度不够，需使用分子/分母表示：使用最大公约数 y / gcd 比 x / gcd.  
                    double k = double(points[i][1] - points[j][1]) / double(points[i][0] - points[j][0]);
                    count[k] += 1;
                }
            }

            res = max(res, sameX + 1);
            for (auto &[key, value]: count) {
                res = max(res, value + 1);
            }
        }

        return res;
    }
};