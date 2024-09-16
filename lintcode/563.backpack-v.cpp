//  Tag: Backpack DP, Dynamic Programming/DP
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given n items with size `nums[i]` which an integer array and all positive numbers.
//  An integer `target` denotes the size of a backpack.
//  Find the number of possible ways to fill the backpack.
//  `Each item may only be used once`
//  
//  Example 1:
//  ```
//  Input:
//  nums = [1,2,3,3,7]
//  target = 7
//  Output:
//  2
//  Explanation:
//  The resulting set is:
//  [7]
//  [1,3,3]
//  Returns 2
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  nums = [1,1,1,1]
//  target = 3
//  Output:
//  4
//  Explanation:
//  Choose 3 out of 4 items, 4 choices in total
//  ```
//  
//  $1 \leq nums.length \leq 1000$
//  $1 \leq target \leq 1000$

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                int weight = nums[i - 1];
                dp[i][j] = dp[i - 1][j];
                if (j >= weight) {
                    dp[i][j] += dp[i - 1][j - weight];
                }
            }
        }

        return dp[n][target];
    }
};

class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= 1; j--) {
                int weight = nums[i - 1];
                if (j >= weight) {
                    dp[j] += dp[j - weight];
                }
            }
        }

        return dp[target];
    }
};