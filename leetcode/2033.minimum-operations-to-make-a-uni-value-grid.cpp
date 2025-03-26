//  Tag: Array, Math, Sorting, Matrix
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/X6gPhyfPNbA

//  You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
//  A uni-value grid is a grid where all the elements of it are equal.
//  Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.
//   
//  Example 1:
//  
//  
//  Input: grid = [[2,4],[6,8]], x = 2
//  Output: 4
//  Explanation: We can make every element equal to 4 by doing the following: 
//  - Add x to 2 once.
//  - Subtract x from 6 once.
//  - Subtract x from 8 twice.
//  A total of 4 operations were used.
//  
//  Example 2:
//  
//  
//  Input: grid = [[1,5],[2,3]], x = 1
//  Output: 5
//  Explanation: We can make every element equal to 3.
//  
//  Example 3:
//  
//  
//  Input: grid = [[1,2],[3,4]], x = 2
//  Output: -1
//  Explanation: It is impossible to make every element equal.
//  
//   
//  Constraints:
//  
//  m == grid.length
//  n == grid[i].length
//  1 <= m, n <= 105
//  1 <= m * n <= 105
//  1 <= x, grid[i][j] <= 104
//  
//  

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> table;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                table.push_back(grid[i][j]);
            }
        }

        sort(table.begin(), table.end());
        int mid = (table.size() - 1) / 2;
        if (table.size() % 2 == 1) {
            return cal(table, table[mid], x);
        } else {
            return min(cal(table, table[mid], x), cal(table, table[mid + 1], x));
        }

    }

    int cal(vector<int> &table, int target, int x) {
        int res = 0;
        for (int i = 0; i < table.size(); i++) {
            if (abs(table[i] - target) % x != 0) {
                return -1;
            }
            res += abs(table[i] - target) / x;
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> table;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                table.push_back(grid[i][j]);
            }
        }

        sort(table.begin(), table.end());
        vector<int> dp(table.size(), 0);
        for (int i = 1; i < table.size(); i++) {
            if ((table[i] - table[i - 1]) % x) {
                return -1;
            }

            dp[i] = dp[i - 1] + i * (table[i] - table[i - 1]) / x;
        }

        int op = 0;
        int res = INT_MAX;
        for (int i = table.size() - 1; i > 0; i--) {
            op += (table.size() - i) * (table[i] - table[i - 1]) / x;
            res = min(res, op + dp[i - 1]);
        }

        return res == INT_MAX ? 0 : res;
    }
};