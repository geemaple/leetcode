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
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int weight = nums[i - 1];
                dp[i][j] = dp[i - 1][j];
                if (j >= weight) {
                    dp[i][j] += dp[i][j - weight];
                }
            }
        }

        return dp[n][target];
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
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                int weight = nums[i - 1];
                if (j >= weight) {
                    dp[j] += dp[j - weight];
                } 
            }
        }

        return dp[target];
    }
};