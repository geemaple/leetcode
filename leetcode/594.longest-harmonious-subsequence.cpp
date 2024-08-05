//  Tag: Array, Hash Table, Sliding Window, Sorting, Counting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
//  Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
//  A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.
//   
//  Example 1:
//  
//  Input: nums = [1,3,2,2,5,2,3,7]
//  Output: 5
//  Explanation: The longest harmonious subsequence is [3,2,2,2,3].
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,4]
//  Output: 2
//  
//  Example 3:
//  
//  Input: nums = [1,1,1,1]
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 2 * 104
//  -109 <= nums[i] <= 109
//  

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> counter;
        for (auto x: nums) {
            counter[x] += 1;
        }

        int res = 0;
        for (auto &[key, val]: counter) {
            if (counter.count(key + 1) > 0) {
                res = max(res, val + counter[key + 1]);
            }
        }
        return res;
    }
};