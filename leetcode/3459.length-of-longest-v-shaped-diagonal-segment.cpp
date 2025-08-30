//  Tag: Array, Dynamic Programming, Memoization, Matrix
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/aZ38GCRokuM

//  You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
//  A V-shaped diagonal segment is defined as:
//  
//  The segment starts with 1.
//  The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
//  The segment:
//  	
//  Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
//  Continues the sequence in the same diagonal direction.
//  Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.
//  
//  
//  
//  
//  Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.
//   
//  Example 1:
//  
//  Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
//  Output: 5
//  Explanation:
//  
//  The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
//  
//  Example 2:
//  
//  Input: grid = [[2,2,2,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
//  Output: 4
//  Explanation:
//  
//  The longest V-shaped diagonal segment has a length of 4 and follows these coordinates: (2,3) → (3,2), takes a 90-degree clockwise turn at (3,2), and continues as (2,1) → (1,0).
//  
//  Example 3:
//  
//  Input: grid = [[1,2,2,2,2],[2,2,2,2,0],[2,0,0,0,0],[0,0,2,2,2],[2,0,0,2,0]]
//  Output: 5
//  Explanation:
//  
//  The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,0) → (1,1) → (2,2) → (3,3) → (4,4).
//  
//  Example 4:
//  
//  Input: grid = [[1]]
//  Output: 1
//  Explanation:
//  The longest V-shaped diagonal segment has a length of 1 and follows these coordinates: (0,0).
//  
//   
//  Constraints:
//  
//  n == grid.length
//  m == grid[i].length
//  1 <= n, m <= 500
//  grid[i][j] is either 0, 1 or 2.
//  
//  

class Solution {
public:
    int directions[4][2] = {{-1,1},{1,1},{1,-1},{-1,-1}};
    int next_val[3] = {2, 2, 0};

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int res = 0;
        int n = grid.size();
        int m = grid[0].size();
        // dp[i][j][d][turn]
        vector dp(n, vector(m, vector(4, vector<int>(2, -1))));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        res = max(res, search(grid, dp, i, j, 1, k, false));
                    }
                }
            }
        }

        return res;
    }

    int search(vector<vector<int>>& grid, vector<vector<vector<vector<int>>>>& dp, int i, int j, int val, int d, bool turn) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != val) {
            return 0;
        }

        if (dp[i][j][d][turn] == -1) {
            int dx = i + directions[d][0];
            int dy = j + directions[d][1];
            int res = 1 + search(grid, dp, dx, dy, next_val[val], d, turn);
            if (!turn) {
                int tx = i + directions[(d + 1) % 4][0];
                int ty = j + directions[(d + 1) % 4][1];
                res = max(res, 1 + search(grid, dp, tx, ty, next_val[val], (d + 1) % 4, true));
            }
            dp[i][j][d][turn] = res;
        }

        return dp[i][j][d][turn];
    }
};