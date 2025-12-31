//  Tag: Array, Hash Table, Math, Matrix
//  Time: O(NM)
//  Space: O(1)
//  Ref: -
//  Note: -

//  A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//  Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?
//  Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.
//   
//  Example 1:
//  
//  
//  Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
//  Output: 1
//  Explanation: 
//  The following subgrid is a 3 x 3 magic square:
//  
//  while this one is not:
//  
//  In total, there is only one magic square inside the given grid.
//  
//  Example 2:
//  
//  Input: grid = [[8]]
//  Output: 0
//  
//   
//  Constraints:
//  
//  row == grid.length
//  col == grid[i].length
//  1 <= row, col <= 10
//  0 <= grid[i][j] <= 15
//  
//  

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                res += check(grid, i, j);
            }
        }
        return res;
    }

    bool check(vector<vector<int>>& grid, int x, int y) {
        if (x + 2 >= grid.size() || y + 2 >= grid[0].size()) {
            return false;
        }

        vector<bool> number(10, false);
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int val = grid[x + i][y + j];
                if (val < 1 || val > 9) {
                    return false;
                }
                if (number[val]) {
                    return false;
                }
                number[val] = true;
            }
        }

        int dig = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int rev = grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y];

        if (dig != rev) {
            return false;
        }

        for (int i = 0; i < 3; i++) {
            if (grid[x + i][y] + grid[x + i][y + 1] + grid[x + i][y + 2] != dig) {
                return false;
            }
        }

        for (int j = 0; j < 3; j++) {
            if (grid[x][y + j] + grid[x + 1][y + j] + grid[x + 2][y + j] != dig) {
                return false;
            }
        }

        return true;
    }
};