//  Tag: Array, Dynamic Programming, Breadth-First Search, Matrix
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
//  The distance between two adjacent cells is 1.
//   
//  Example 1:
//  
//  
//  Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
//  Output: [[0,0,0],[0,1,0],[0,0,0]]
//  
//  Example 2:
//  
//  
//  Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
//  Output: [[0,0,0],[0,1,0],[1,2,1]]
//  
//   
//  Constraints:
//  
//  m == mat.length
//  n == mat[i].length
//  1 <= m, n <= 104
//  1 <= m * n <= 104
//  mat[i][j] is either 0 or 1.
//  There is at least one 0 in mat.
//  
//  

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0 && dp[i - 1][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }

                    if (j > 0 && dp[i][j - 1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i + 1 < m && dp[i + 1][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }

                    if (j + 1 < n && dp[i][j + 1] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }

        return dp;
    }
};

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push(make_pair(i, j));
                } else{     
                    mat[i][j] = -1;
                }
            }
        }

        int directions[] = {-1, 0, 1, 0, -1};
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int dx = p.first + directions[k];
                int dy = p.second + directions[k + 1];

                if (dx >= 0 && dx < m && dy >=0 && dy < n && mat[dx][dy] == -1) {
                    mat[dx][dy] = mat[p.first][p.second] + 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }

        return mat;
    }
};