//  Tag: Array, Dynamic Programming
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, find a subarray that has the largest product, and return the product.
//  The test cases are generated so that the answer will fit in a 32-bit integer.
//   
//  Example 1:
//  
//  Input: nums = [2,3,-2,4]
//  Output: 6
//  Explanation: [2,3] has the largest product 6.
//  
//  Example 2:
//  
//  Input: nums = [-2,0,-1]
//  Output: 0
//  Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 2 * 104
//  -10 <= nums[i] <= 10
//  The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
//  
//  

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int min_pre = nums[0];
        int max_pre = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                swap(min_pre, max_pre);
            }

            max_pre = max(nums[i], max_pre * nums[i]);
            min_pre = min(nums[i], min_pre * nums[i]);
            res = max(res, max_pre);
        }

        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
            res = max(res, dp[i][i]);
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                dp[i][j] = max(dp[i + 1][j] * nums[i], dp[i][j - 1] * nums[j]);
                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};