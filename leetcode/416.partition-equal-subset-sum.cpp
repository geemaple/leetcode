//  Tag: Array, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/5uRXSdLOz1o

//  Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
//   
//  Example 1:
//  
//  Input: nums = [1,5,11,5]
//  Output: true
//  Explanation: The array can be partitioned as [1, 5, 5] and [11].
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,5]
//  Output: false
//  Explanation: The array cannot be partitioned into equal sum subsets.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 200
//  1 <= nums[i] <= 100
//  
//  

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) {
            return false;
        }

        int n = nums.size();
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = target; j >= nums[i - 1]; j--) {
                dp[j] = dp[j] || dp[j - nums[i - 1]];
            }
        }

        return dp[target];
    }
};

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) {
            return false;
        }

        int n = nums.size();
        int k = total / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][k];
    }
};