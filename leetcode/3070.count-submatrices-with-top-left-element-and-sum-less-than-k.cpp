//  Tag: Array, Matrix, Prefix Sum
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  You are given a 0-indexed integer matrix grid and an integer k.
//  Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
//   
//  Example 1:
//  
//  
//  Input: grid = [[7,6,3],[6,6,1]], k = 18
//  Output: 4
//  Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
//  Example 2:
//  
//  
//  Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
//  Output: 6
//  Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
//  
//   
//  Constraints:
//  
//  m == grid.length 
//  n == grid[i].length
//  1 <= n, m <= 1000 
//  0 <= grid[i][j] <= 1000
//  1 <= k <= 109
//  
//  

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> arr(n, vector<int>(m, 0));
        int res = 0;
        
        for (int i = 0; i < n; ++i) {
            int prefix = 0;
            for (int j = 0; j < m; ++j) {
                prefix += grid[i][j];
                if (i == 0 && j == 0) {
                    arr[i][j] = grid[i][j];
                } else if (i == 0) {
                    arr[i][j] = arr[i][j - 1] + grid[i][j];
                } else {
                    arr[i][j] = arr[i - 1][j] + prefix;
                }
                
                res += arr[i][j] <= k;                   
            }
        }
        
        return res;
    }
};