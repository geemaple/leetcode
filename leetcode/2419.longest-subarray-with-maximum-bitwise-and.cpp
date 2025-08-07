//  Tag: Array, Bit Manipulation, Brainteaser
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/eESJBvObZZU

//  You are given an integer array nums of size n.
//  Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
//  
//  In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
//  
//  Return the length of the longest such subarray.
//  The bitwise AND of an array is the bitwise AND of all the numbers in it.
//  A subarray is a contiguous sequence of elements within an array.
//   
//  Example 1:
//  
//  Input: nums = [1,2,3,3,2,2]
//  Output: 2
//  Explanation:
//  The maximum possible bitwise AND of a subarray is 3.
//  The longest subarray with that value is [3,3], so we return 2.
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,4]
//  Output: 1
//  Explanation:
//  The maximum possible bitwise AND of a subarray is 4.
//  The longest subarray with that value is [4], so we return 1.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 106
//  
//  

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int biggest = *max_element(begin(nums), end(nums));
        int res = 0;
        int count = 0;
        for (auto &x: nums) {
            count = (x == biggest)? count + 1: 0;
            res = max(res, count);
        }
        return res;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int biggest = 0;
        int res = 0;
        int count = 0;
        for (auto &x: nums) {
            if (biggest < x) {
                biggest = x;
                count = 0;
                res = 0;
            }
            count = (x == biggest)? count + 1: 0;
            res = max(res, count);
        }
        return res;
    }
};