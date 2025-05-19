//  Tag: Dynamic Programming
//  Time: O(N * 48 ^ 2)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/mVdxVHIq4hQ

//  You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//  Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  
//  Input: m = 1, n = 1
//  Output: 3
//  Explanation: The three possible colorings are shown in the image above.
//  
//  Example 2:
//  
//  
//  Input: m = 1, n = 2
//  Output: 6
//  Explanation: The six possible colorings are shown in the image above.
//  
//  Example 3:
//  
//  Input: m = 5, n = 5
//  Output: 580986
//  
//   
//  Constraints:
//  
//  1 <= m <= 5
//  1 <= n <= 1000
//  
//  

class Solution {
public:
    int dp[1001][1024] = {};
    int mod = 1e9 + 7;
    int colorTheGrid(int m, int n) {
        return dfs(m, n, 0, 0, 0, 0);
    }

    int dfs(int m, int n, int i, int j, int cur, int pre) {
        if (i == m) {
            return dfs(m, n, 0, j + 1, 0, cur);
        }

        if (j == n) {
            return 1;
        }

        if (i == 0 && dp[j][pre] > 0) {
            return dp[j][pre];
        }

        int up = i == 0 ? 0 : (cur >> (i - 1) * 2) & 3;
        int left = (pre >> i * 2) & 3;
        int res = 0;
        for (int k = 1; k <=3; k++) {
            if (k != up && k != left) {
                res = (res * 1LL + dfs(m, n, i + 1, j, k << i * 2 | cur, pre)) % mod;
            }
        }

        if (i == 0) {
            dp[j][pre] = res;
        }

        return res;
    }
};