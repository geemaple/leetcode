//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: O(NKT)
//  Space: O(NKT)
//  Ref: -
//  Note: -

//  Given `n` distinct positive integers, integer `k` $(k \leq n)$ and a number `target`.
//  
//  Find `k` numbers where sum is target.
//  Calculate how many solutions there are?
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  A = [1,2,3,4]
//  k = 2
//  target = 5
//  ``` 
//  Output:  
//  ``` 
//  2
//  ``` 
//  Explanation:  
//  
//  1 + 4 = 2 + 3 = 5
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  A = [1,2,3,4,5]
//  k = 3
//  target = 6
//  ``` 
//  Output:  
//  ``` 
//  1
//  ``` 
//  Explanation:  
//  
//  There is only one method. 1 + 2 + 3 = 6
//  
//  

class Solution {
public:
    /**
     * @param a: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &a, int k, int target) {
        // write your code here
        int n = a.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (k + 1, vector<int>(target + 1, 0)));
        dp[0][0][0] = 1;

        for (int i = 1; i <=n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int t = 0; t <= target; t++) {
                    dp[i][j][t] = dp[i - 1][j][t];
                    if (j - 1 >= 0 && t - a[i - 1] >= 0) {
                        dp[i][j][t] += dp[i - 1][j - 1][t - a[i - 1]];
                    }
                }
            }
        }

        return dp[n][k][target];
    }
};

class Solution {
public:
    /**
     * @param a: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integer
     */
    int kSum(vector<int> &a, int k, int target) {
        // write your code here
        int n = a.size();
        vector<vector<int>> dp(k + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;

        for (int num: a) {
            for (int j = k; j >= 1; j--) {
                for (int t = target; t >= num; t--) {
                    dp[j][t] += dp[j - 1][t - num];
                }
            }
        }

        return dp[k][target];
    }
};