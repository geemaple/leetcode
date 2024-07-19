//  Tag: Array, Dynamic Programming
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
//  Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
//   
//  Example 1:
//  
//  Input: nums = [2,3,2]
//  Output: 3
//  Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,1]
//  Output: 4
//  Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//  Total amount you can rob = 1 + 3 = 4.
//  
//  Example 3:
//  
//  Input: nums = [1,2,3]
//  Output: 3
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 100
//  0 <= nums[i] <= 1000
//  
//  

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);

        return max(helper(nums1), helper(nums2));
    }

    int helper(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[1] = nums[0];

        for (int i = 2; i <= n; i++) {
            int v = nums[i - 1];
            dp[i] = max(dp[i - 1], dp[i - 2] + v);
        }

        return dp[n];
    }
};