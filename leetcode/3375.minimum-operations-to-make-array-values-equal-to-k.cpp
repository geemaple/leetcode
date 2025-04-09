//  Tag: Array, Hash Table
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/k7bLSrx0Dgk

//  You are given an integer array nums and an integer k.
//  An integer h is called valid if all values in the array that are strictly greater than h are identical.
//  For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.
//  You are allowed to perform the following operation on nums:
//  
//  Select an integer h that is valid for the current values in nums.
//  For each index i where nums[i] > h, set nums[i] to h.
//  
//  Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.
//   
//  Example 1:
//  
//  Input: nums = [5,2,5,4,5], k = 2
//  Output: 2
//  Explanation:
//  The operations can be performed in order using valid integers 4 and then 2.
//  
//  Example 2:
//  
//  Input: nums = [2,1,2], k = 2
//  Output: -1
//  Explanation:
//  It is impossible to make all the values equal to 2.
//  
//  Example 3:
//  
//  Input: nums = [9,7,5,3], k = 1
//  Output: 4
//  Explanation:
//  The operations can be performed using valid integers in the order 7, 5, 3, and 1.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 100 
//  1 <= nums[i] <= 100
//  1 <= k <= 100
//  
//  

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> elements(nums.begin(), nums.end());
        int res = 0;
        for (auto x: elements) {
            if (x < k) {
                return -1;
            }

            if (x > k) {
                res += 1;
            }
        }

        return res;
    }
};