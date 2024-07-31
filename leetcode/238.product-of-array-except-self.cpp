//  Tag: Array, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
//  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//  You must write an algorithm that runs in O(n) time and without using the division operation.
//   
//  Example 1:
//  Input: nums = [1,2,3,4]
//  Output: [24,12,8,6]
//  Example 2:
//  Input: nums = [-1,1,0,-3,3]
//  Output: [0,0,9,0,0]
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 105
//  -30 <= nums[i] <= 30
//  The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
//  
//   
//  Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
//  

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = nums;
        vector<int> suffix = nums;
        vector<int> res;
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i] * prefix[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i] * suffix[i + 1];
        }

        for (int i = 0; i < n; i++) {
            int l = i - 1 >= 0 ? prefix[i - 1] : 1;
            int r = i + 1 < n ? suffix[i + 1] : 1;
            res.push_back(l * r);
        }

        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res = vector<int>(n, 1);

        int left = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left;
            left = left * nums[i];
        }

        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right = right * nums[i];
        }

        return res;
    }
};