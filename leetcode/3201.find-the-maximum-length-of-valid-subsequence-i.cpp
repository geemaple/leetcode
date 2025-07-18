//  Tag: Array, Dynamic Programming
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/mMkCu3nFfV8

//  You are given an integer array nums.
//  A subsequence sub of nums with length x is called valid if it satisfies:
//  
//  (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
//  
//  Return the length of the longest valid subsequence of nums.
//  A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
//   
//  Example 1:
//  
//  Input: nums = [1,2,3,4]
//  Output: 4
//  Explanation:
//  The longest valid subsequence is [1, 2, 3, 4].
//  
//  Example 2:
//  
//  Input: nums = [1,2,1,1,2,1,2]
//  Output: 6
//  Explanation:
//  The longest valid subsequence is [1, 2, 1, 2, 1, 2].
//  
//  Example 3:
//  
//  Input: nums = [1,3]
//  Output: 2
//  Explanation:
//  The longest valid subsequence is [1, 3].
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 2 * 105
//  1 <= nums[i] <= 107
//  
//  

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(2, 0));
        int res = 0;
        for (auto a: nums) {
            for (int b = 0; b < 2; b++) {
                dp[b][a % 2] = dp[a % 2][b] + 1;
                res = max(res, dp[b][a % 2]);
            }
        }

        return res;
    }
};