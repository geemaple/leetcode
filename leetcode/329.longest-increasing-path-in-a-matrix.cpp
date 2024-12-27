//  Tag: Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Topological Sort, Memoization, Matrix
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  Given an m x n integers matrix, return the length of the longest increasing path in matrix.
//  From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).
//   
//  Example 1:
//  
//  
//  Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
//  Output: 4
//  Explanation: The longest increasing path is [1, 2, 6, 9].
//  
//  Example 2:
//  
//  
//  Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
//  Output: 4
//  Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//  
//  Example 3:
//  
//  Input: matrix = [[1]]
//  Output: 1
//  
//   
//  Constraints:
//  
//  m == matrix.length
//  n == matrix[i].length
//  1 <= m, n <= 200
//  0 <= matrix[i][j] <= 231 - 1
//  
//  

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res = max(res, dfs(i, j, matrix, dp));
            }
        }
        return res;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix,  vector<vector<int>>&dp) {
        if (dp[i][j] == 0) {
            int n = matrix.size();
            int m = matrix[0].size();
            int directions[] = {-1, 0, 1, 0, -1};
            int res = 1;
            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > matrix[i][j]) {
                    res = max(res, 1 + dfs(x, y, matrix, dp));
                }
            }
            dp[i][j] = res;
        }

        return dp[i][j];
    }

};