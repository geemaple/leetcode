//  Tag: Array, Dynamic Programming, Matrix
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//   
//  Example 1:
//  
//  
//  Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
//  Output: 4
//  
//  Example 2:
//  
//  
//  Input: matrix = [["0","1"],["1","0"]]
//  Output: 1
//  
//  Example 3:
//  
//  Input: matrix = [["0"]]
//  Output: 0
//  
//   
//  Constraints:
//  
//  m == matrix.length
//  n == matrix[i].length
//  1 <= m, n <= 300
//  matrix[i][j] is '0' or '1'.
//  
//  

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int d = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                    }

                    d = max(d, dp[i][j]);
                }
            }
        }

        return d * d;
    }
};