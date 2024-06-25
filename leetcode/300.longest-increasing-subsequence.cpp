//  Category: Array, Binary Search, Dynamic Programming
//  Time: O(N*logN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array nums, return the length of the longest strictly increasing subsequence.
//   
//  Example 1:
//  
//  Input: nums = [10,9,2,5,3,7,101,18]
//  Output: 4
//  Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
//  
//  Example 2:
//  
//  Input: nums = [0,1,0,3,2,3]
//  Output: 4
//  
//  Example 3:
//  
//  Input: nums = [7,7,7,7,7,7,7]
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 2500
//  -104 <= nums[i] <= 104
//  
//   
//  Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
//  

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int n : nums) {
            auto it = lower_bound(res.begin(), res.end(), n);
            if (it == res.end()) {
                res.push_back(n);
            } else {
                *it = n;
            }
        }

        return res.size();
    }
};


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++ ) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

