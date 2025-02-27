//  Tag: Array, Binary Search, Sliding Window, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
//   
//  Example 1:
//  
//  Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
//  Output: 6
//  Explanation: [1,1,1,0,0,1,1,1,1,1,1]
//  Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
//  Example 2:
//  
//  Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
//  Output: 10
//  Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
//  Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  nums[i] is either 0 or 1.
//  0 <= k <= nums.length
//  
//  

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int zero = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            zero += nums[j] == 0;
            while (zero > k) {
                zero -= nums[i] == 0;
                i += 1;
            }
            res = max(res, j - i + 1);
        }

        return res;
    }
};

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int zero = 0;
        for (int j = 0; j < n; j++) {
            zero += nums[j] == 0;
            if (zero > k) {
                zero -= nums[i] == 0;
                i += 1;
            }
        }

        return n - i;
    }
};