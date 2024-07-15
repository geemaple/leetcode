//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given `n` items with size $A_{i}$ an integer `m` denotes the size of a backpack.
//  How full you can fill this backpack?
//  (Each item can only be selected once and the size of the item is a positive integer)
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  array = [3,4,8,5]
//  backpack size = 10
//  ``` 
//  Output:  
//  ``` 
//  9
//  ``` 
//  Explanation:  
//  
//  Load 4 and 5.
//  
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  array = [2,3,5,7]
//  backpack size = 12
//  ``` 
//  Output:  
//  ``` 
//  12
//  ``` 
//  Explanation:  
//  
//  Load 5 and 7.
//  
//  * You can not divide any item into small pieces.
//  * $n \lt 1000$
//  * $m \lt 1e9$

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param a: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &a) {
        // write your code here
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int w = a[i - 1];
                int v = a[i - 1];
                if (w <= j) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
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
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &a) {
        // write your code here
        int n = a.size();
        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                int w = a[i - 1];
                int v = a[i - 1];
                if (w <= j) {
                    dp[j] = max(dp[j], dp[j - w] + v);
                }
            }
        }

        return dp[m];
    }
};