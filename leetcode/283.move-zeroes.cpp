//  Tag: Array, Two Pointers
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//  Note that you must do this in-place without making a copy of the array.
//   
//  Example 1:
//  Input: nums = [0,1,0,3,12]
//  Output: [1,3,12,0,0]
//  Example 2:
//  Input: nums = [0]
//  Output: [0]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 104
//  -231 <= nums[i] <= 231 - 1
//  
//   
//  Follow up: Could you minimize the total number of operations done?

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for(auto j = 0; j < n; ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int l = 0;
        while (i < n && l < n) {
            while (l < n && nums[l] != 0) {
                l += 1;
            }

            i = max(i, l + 1);
            while (i < n && nums[i] == 0) {
                i += 1;
            }

            if (i < n && l < n) {
                swap(nums[l], nums[i]);
                l += 1;
                i += 1;
            }
        }
    }
};