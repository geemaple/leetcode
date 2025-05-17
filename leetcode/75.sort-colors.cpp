//  Tag: Array, Two Pointers, Sorting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/zJ1zc2-ymJM

//  Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//  We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//  You must solve this problem without using the library's sort function.
//   
//  Example 1:
//  
//  Input: nums = [2,0,2,1,1,0]
//  Output: [0,0,1,1,2,2]
//  
//  Example 2:
//  
//  Input: nums = [2,0,1]
//  Output: [0,1,2]
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 300
//  nums[i] is either 0, 1, or 2.
//  
//   
//  Follow up: Could you come up with a one-pass algorithm using only constant extra space?
//  

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int i = 0;

        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                i += 1;
                l += 1;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r -= 1;
            } else {
                i++;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                swap(nums[l], nums[i]);
                l += 1;
            }
        }
        
        for (int i = l; i < nums.size(); i++) {
            if (nums[i] == 1) {
                swap(nums[l], nums[i]);
                l += 1;
            }
        }
        
    }
};