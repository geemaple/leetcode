//  Tag: Array, Divide and Conquer, Dynamic Programming
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array nums, find the subarray with the largest sum, and return its sum.
//   
//  Example 1:
//  
//  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
//  Output: 6
//  Explanation: The subarray [4,-1,2,1] has the largest sum 6.
//  
//  Example 2:
//  
//  Input: nums = [1]
//  Output: 1
//  Explanation: The subarray [1] has the largest sum 1.
//  
//  Example 3:
//  
//  Input: nums = [5,4,-1,7,8]
//  Output: 23
//  Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  -104 <= nums[i] <= 104
//  
//   
//  Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//  

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(0, dp[i - 1]) + nums[i];
        }

        return *max_element(dp.begin(), dp.end());
    }
}; 

// prefix-sum
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sumJ = 0;
        int sumI = 0;
        int largest = INT_MIN;
        
        // sub[i+1: j] = sum[:j] - sum[:i]
        for (auto i = 0; i < nums.size(); ++i) {
            sumJ += nums[i];
            largest = max(largest, sumJ - sumI);
            sumI = min(sumI, sumJ);
        }
        
        return largest;
    }
};

// follow-up
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }

    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }

        int mid = (left + right) >> 1; 
        int cur = 0;
        int left_max = INT_MIN;
        for (int i = mid; i >= left; i--) {
            cur += nums[i];
            left_max = max(left_max, cur);
        }

        cur = 0;
        int right_max = INT_MIN;
        for (int i = mid + 1; i <= right; i++) {
            cur += nums[i];
            right_max = max(right_max, cur);
        }

        int child_max = max(helper(nums, left, mid), helper(nums, mid + 1, right));
        return max(child_max, left_max + right_max);

    }
};