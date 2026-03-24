//  Tag: Array, Matrix, Prefix Sum
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
//  
//  grid[0][0]
//  an equal frequency of 'X' and 'Y'.
//  at least one 'X'.
//  
//   
//  Example 1:
//  
//  Input: grid = [["X","Y","."],["Y",".","."]]
//  Output: 3
//  Explanation:
//  
//  
//  Example 2:
//  
//  Input: grid = [["X","X"],["X","Y"]]
//  Output: 0
//  Explanation:
//  No submatrix has an equal frequency of 'X' and 'Y'.
//  
//  Example 3:
//  
//  Input: grid = [[".","."],[".","."]]
//  Output: 0
//  Explanation:
//  No submatrix has at least one 'X'.
//  
//   
//  Constraints:
//  
//  1 <= grid.length, grid[i].length <= 1000
//  grid[i][j] is either 'X', 'Y', or '.'.
//  
//  

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> x(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> y(m + 1, vector<int>(n + 1, 0));

        int res = 0;

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                x[i][j] = x[i - 1][j] + x[i][j - 1] - x[i - 1][j - 1] 
                        + (grid[i - 1][j - 1] == 'X' ? 1 : 0);

                y[i][j] = y[i - 1][j] + y[i][j - 1] - y[i - 1][j - 1] 
                        + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);

                if (x[i][j] > 0 && x[i][j] == y[i][j]) {
                    ++res;
                }
            }
        }

        return res;
    }
};