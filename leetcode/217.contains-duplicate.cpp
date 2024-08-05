//  Tag: Array, Hash Table, Sorting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
//   
//  Example 1:
//  Input: nums = [1,2,3,1]
//  Output: true
//  Example 2:
//  Input: nums = [1,2,3,4]
//  Output: false
//  Example 3:
//  Input: nums = [1,1,1,3,3,4,3,2,4,2]
//  Output: true
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  
//  

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto x: nums) {
            if (set.count(x) > 0) {
                return true;
            }
            set.insert(x);
        }

        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        return nums.size() != set.size();
    }
};