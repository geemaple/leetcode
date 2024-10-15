//  Tag: Array, Dynamic Programming, Matrix
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//  Note: You can only move either down or right at any point in time.
//   
//  Example 1:
//  
//  
//  Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
//  Output: 7
//  Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
//  
//  Example 2:
//  
//  Input: grid = [[1,2,3],[4,5,6]]
//  Output: 12
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 200
//  0 <= grid[i][j] <= 200
//  
//  

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[i][j];
                } else if (i == 0) {
                    dp[0][j] = dp[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    dp[i][0] = dp[i - 1][j] + grid[i][j];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};