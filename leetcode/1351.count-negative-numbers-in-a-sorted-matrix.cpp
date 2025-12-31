//  Tag: Array, Binary Search, Matrix
//  Time: O(N + M)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.
//   
//  Example 1:
//  
//  Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
//  Output: 8
//  Explanation: There are 8 negatives number in the matrix.
//  
//  Example 2:
//  
//  Input: grid = [[3,2],[1,0]]
//  Output: 0
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 100
//  -100 <= grid[i][j] <= 100
//  
//   
//  Follow up: Could you find an O(n + m) solution?

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = n - 1;
        int j = 0;
        int res = 0;
        while (i >= 0 && j < m) {
            if (grid[i][j] < 0) {
                res += m - j;
                i -= 1;
            } else {
                j += 1;
            }
        }
        return res;
    }
};