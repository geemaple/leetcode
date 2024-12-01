//  Tag: Array, Hash Table, Prefix Sum
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
//   
//  Example 1:
//  
//  Input: nums = [0,1]
//  Output: 2
//  Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
//  
//  Example 2:
//  
//  Input: nums = [0,1,0]
//  Output: 2
//  Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  nums[i] is either 0 or 1.
//  
//  

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> table;
        table[0] = -1;
        int preifx_sum = 0;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            preifx_sum += nums[i] == 0 ? -1 : 1;
            if (table.count(preifx_sum) > 0) {
                res = max(res, i - table[preifx_sum]);
            } else {
                table[preifx_sum] = i;
            }
        }
        return res;
    }
};