//  Tag: Array, Binary Search, Sliding Window, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
//   
//  Example 1:
//  
//  Input: target = 7, nums = [2,3,1,2,4,3]
//  Output: 2
//  Explanation: The subarray [4,3] has the minimal length under the problem constraint.
//  
//  Example 2:
//  
//  Input: target = 4, nums = [1,4,4]
//  Output: 1
//  
//  Example 3:
//  
//  Input: target = 11, nums = [1,1,1,1,1,1,1,1]
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= target <= 109
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 104
//  
//   
//  Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        int res = INT_MAX;
        int i = 0;

        for (int j = 0; j < n; j++) {
            total += nums[j];

            while (total >= target) {
                res = min(res, j - i + 1);
                total -= nums[i];
                i ++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// follow up
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }

        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = prefix[i];
            auto it = lower_bound(prefix.begin(), prefix.end(), x + target);
            if (it != prefix.end()) {
                res = min(res, int(it - prefix.begin() - i));
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};