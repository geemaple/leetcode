//  Tag: Array, Hash Table, Bit Manipulation, Sorting, Index Sort
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
//  You are given an integer array nums representing the data status of this set after the error.
//  Find the number that occurs twice and the number that is missing and return them in the form of an array.
//   
//  Example 1:
//  Input: nums = [1,2,2,4]
//  Output: [2,3]
//  Example 2:
//  Input: nums = [1,1]
//  Output: [1,2]
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 104
//  1 <= nums[i] <= 104
//  
//  

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int i = 1;
        while (i < nums.size()) {
            int j = nums[i];
            if (i > 0 && i < nums.size() && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i += 1;
            }
        }
        vector<int> res;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                res.push_back(nums[i]);
                res.push_back(i);
            }
        }
        return res;
    }
};