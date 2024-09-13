//  Tag: Array, Dynamic Programming, Greedy
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
//  Return true if you can reach the last index, or false otherwise.
//   
//  Example 1:
//  
//  Input: nums = [2,3,1,1,4]
//  Output: true
//  Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//  
//  Example 2:
//  
//  Input: nums = [3,2,1,0,4]
//  Output: false
//  Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 104
//  0 <= nums[i] <= 105
//  
//  

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cur = nums[0];
        for (int i = 1; i < n; i++) {
            if (i > cur) {
                return false;
            }
            cur = max(cur, i + nums[i]);
        }   
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && i - j <= nums[j]) {
                    dp[i] = true;
                    break;
                }

            }
        } 

        return dp[n - 1];
    }
};