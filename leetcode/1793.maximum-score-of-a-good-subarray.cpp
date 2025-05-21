//  Tag: Array, Two Pointers, Binary Search, Stack, Monotonic Stack
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an array of integers nums (0-indexed) and an integer k.
//  The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
//  Return the maximum possible score of a good subarray.
//   
//  Example 1:
//  
//  Input: nums = [1,4,3,7,4,5], k = 3
//  Output: 15
//  Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15. 
//  
//  Example 2:
//  
//  Input: nums = [5,5,4,5,4,1,1,1], k = 0
//  Output: 20
//  Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 2 * 104
//  0 <= k < nums.length
//  
//  

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int l = k;
        int r = k;
        int res = nums[k];
        int low = nums[k];
        while (r - l + 1 < n) {
            if (l == 0) {
                r += 1;
            } else if (r == n - 1) {
                l -= 1;
            } else if (nums[l - 1] < nums[r + 1]) {
                r += 1;
            } else {
                l -= 1;
            }
            low = min(low, min(nums[l], nums[r]));
            res = max(res, low * (r - l + 1));
        }
        return res;
    }
};