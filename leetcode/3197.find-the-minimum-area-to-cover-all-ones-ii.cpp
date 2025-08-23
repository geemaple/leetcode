//  Tag: Array, Matrix, Enumeration
//  Time: O(N^2M^2)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/2xIqXuUSS-o

//  You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
//  Return the minimum possible sum of the area of these rectangles.
//  Note that the rectangles are allowed to touch.
//   
//  Example 1:
//  
//  Input: grid = [[1,0,1],[1,1,1]]
//  Output: 5
//  Explanation:
//  
//  
//  The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
//  The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
//  The 1 at (1, 1) is covered by a rectangle of area 1.
//  
//  
//  Example 2:
//  
//  Input: grid = [[1,0,1,0],[0,1,0,1]]
//  Output: 5
//  Explanation:
//  
//  
//  The 1's at (0, 0) and (0, 2) are covered by a rectangle of area 3.
//  The 1 at (1, 1) is covered by a rectangle of area 1.
//  The 1 at (1, 3) is covered by a rectangle of area 1.
//  
//  
//   
//  Constraints:
//  
//  1 <= grid.length, grid[i].length <= 30
//  grid[i][j] is either 0 or 1.
//  The input is generated such that there are at least three 1's in grid.
//  
//  

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n - 1; i++) {
            res = min({res,
                cal(grid, 0, 0, i, m - 1) + h_split(grid, i + 1, 0, n - 1, m - 1),
                cal(grid, 0, 0, i, m - 1) + v_split(grid, i + 1, 0, n - 1, m - 1),
                v_split(grid, 0, 0, i, m - 1) + cal(grid, i + 1, 0, n - 1, m - 1)
            });
        }

        for (int j = 0; j < m - 1; j++) {
            res = min({res,
                cal(grid, 0, 0, n - 1, j) + h_split(grid, 0, j + 1, n - 1, m - 1),
                cal(grid, 0, 0, n - 1, j) + v_split(grid, 0, j + 1, n - 1, m - 1),
                h_split(grid, 0, 0, n - 1, j) + cal(grid, 0, j + 1, n - 1, m - 1)
            });
        }

        return res; 
    }

    int h_split(vector<vector<int>>& grid, int t, int l, int b, int r) {
        int res = INT_MAX;
        for (int i = t; i <= b; i++) {
            res = min(res, cal(grid, t, l, i, r) + cal(grid, i + 1, l, b, r));
        }
        return res;
    }

    int v_split(vector<vector<int>>& grid, int t, int l, int b, int r) {
        int res = INT_MAX;
        for (int j = l; j <= r; j++) {
            res = min(res, cal(grid, t, l, b, j) + cal(grid, t, j + 1, b, r));
        }
        return res;
    }

    int cal(vector<vector<int>>& grid, int t, int l, int b, int r) {
        int top = b;
        int bottom = t;
        int left = r;
        int right = l;

        for (int i = t; i <= b; i++) {
            for (int j = l; j <= r; j++) {
                if (grid[i][j] == 1) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        int res = (right - left + 1) * (bottom - top + 1);
        return res >= 1 ? res : 30 * 30; // max grid area
    }
};