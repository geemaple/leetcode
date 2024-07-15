//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  Give `n` items and an array, `num[i]` indicate the size of `i`th item.
//  An integer `target` denotes the size of backpack.
//  Find the number of ways to fill the backpack.
//  
//  `Each item may be chosen unlimited number of times`
//  
//  **Example1**
//  
//  ```
//  Input: nums = [2,3,6,7] and target = 7
//  Output: 2
//  Explanation:
//  Solution sets are: 
//  [7]
//  [2, 2, 3]
//  ```
//  
//  **Example2**
//  
//  ```
//  Input: nums = [2,3,4,5] and target = 7
//  Output: 3
//  Explanation:
//  Solution sets are: 
//  [2, 5]
//  [3, 4]
//  [2, 2, 3]
//  ```
//  
//  

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        int m = target;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int w = nums[i - 1];
                if (w <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - w];
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
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        int m = target;
        vector<int> dp(m + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int w = nums[i - 1];
                if (w <= j) {
                    dp[j] = dp[j] + dp[j - w];
                }
            }
        }

        return dp[m];
    }
};