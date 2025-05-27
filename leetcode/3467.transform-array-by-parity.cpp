//  Tag: Array, Sorting, Counting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an integer array nums. Transform nums by performing the following operations in the exact order specified:
//  
//  Replace each even number with 0.
//  Replace each odd numbers with 1.
//  Sort the modified array in non-decreasing order.
//  
//  Return the resulting array after performing these operations.
//   
//  Example 1:
//  
//  Input: nums = [4,3,2,1]
//  Output: [0,0,1,1]
//  Explanation:
//  
//  Replace the even numbers (4 and 2) with 0 and the odd numbers (3 and 1) with 1. Now, nums = [0, 1, 0, 1].
//  After sorting nums in non-descending order, nums = [0, 0, 1, 1].
//  
//  
//  Example 2:
//  
//  Input: nums = [1,5,1,4,2]
//  Output: [0,0,1,1,1]
//  Explanation:
//  
//  Replace the even numbers (4 and 2) with 0 and the odd numbers (1, 5 and 1) with 1. Now, nums = [1, 1, 1, 0, 0].
//  After sorting nums in non-descending order, nums = [0, 0, 1, 1, 1].
//  
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 100
//  1 <= nums[i] <= 1000
//  
//  

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }

        int l = 0;
        int r = n - 1;
        while (l < r) {
            while (l < r && nums[l] == 0) {
                l += 1;
            }
            while (l < r && nums[r] == 1) {
                r -= 1;
            }

            if (l < r) {
                swap(nums[l], nums[r]);
                l += 1;
                r -= 1;
            }
        }

        return nums;
    }
};