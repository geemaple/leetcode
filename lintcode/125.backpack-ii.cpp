//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  There are `n` items and a backpack with size `m`.
//  Given array `A` representing the size of each item and array `V` representing the value of each item.
//  
//  What's the maximum value can you put into the backpack?
//  
//  **Example 1:**
//   
//  Input:
//  ``` 
//  m = 10
//  A = [2, 3, 5, 7]
//  V = [1, 5, 2, 4]
//  ``` 
//  Output:
//  ```
//  9
//  ```
//  Explanation:
//  
//  Put A[1] and A[3] into backpack, getting the maximum value V[1] + V[3] = 9 
//  
//  **Example 2:**
//   
//  Input:
//  ``` 
//  m = 10
//  A = [2, 3, 8]
//  V = [2, 5, 8]
//  ``` 
//  Output:
//  ```
//  10
//  ```
//  Explanation:
//  
//  Put A[0] and A[2] into backpack, getting the maximum value V[0] + V[2] = 10
//  
//  1. `A[i], V[i], n, m` are all integers.
//  2. You can not split an item.
//  3. The sum size of the items you want to put into backpack can not exceed `m`.
//  4. Each item can only be picked up once
//  5. $m <= 1000$\
//  $len(A),len(V)<=100$

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &a, vector<int> &v) {
        // write your code here
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int w = a[i - 1];
                int val = v[i - 1];
                if (w <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + val);
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
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @param v: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &a, vector<int> &v) {
        // write your code here
        int n = a.size();
        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                int w = a[i - 1];
                int val = v[i - 1];
                if (w <= j) {
                    dp[j] = max(dp[j], dp[j - w] + val);
                }
            }
        }

        return dp[m];
    }
};