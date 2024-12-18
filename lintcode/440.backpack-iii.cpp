//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  Given `n` kinds of items, and each kind of item has an infinite number available.
//  The `i-th` item has size `A[i]` and value `V[i]`.
//  
//  Also given a backpack with size `m`.
//  What is the maximum value you can put into the backpack?
//  
//  **Example 1:**
//  
//  ```
//  Input: A = [2, 3, 5, 7], V = [1, 5, 2, 4], m = 10
//  Output: 15
//  Explanation: Put three item 1 (A[1] = 3, V[1] = 5) into backpack.
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: A = [1, 2, 3], V = [1, 2, 3], m = 5
//  Output: 5
//  Explanation: Strategy is not unique. For example, put five item 0 (A[0] = 1, V[0] = 1) into backpack.
//  ```
//  
//  1. You cannot divide item into small pieces.
//  2. Total size of items you put into backpack can not exceed `m`.

class Solution {
public:
    /**
     * @param a: an integer array
     * @param v: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &a, vector<int> &v, int m) {
        // write your code here
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int weight = a[i - 1];
                int val = v[i - 1];
                if (j >= weight) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - weight] + val);
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};

class Solution {
public:
    /**
     * @param a: an integer array
     * @param v: an integer array
     * @param m: An integer
     * @return: an array
     */
    int backPackIII(vector<int> &a, vector<int> &v, int m) {
        // write your code here
        int n = a.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int weight = a[i - 1];
                int val = v[i - 1];
                if (j >= weight) {
                    dp[j] = max(dp[j], dp[j - weight] + val);
                }
            }
        }

        return dp[m];
    }
};