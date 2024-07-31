//  Tag: Array, Hash Table
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
//   
//  Example 1:
//  Input: nums = [4,3,2,7,8,2,3,1]
//  Output: [5,6]
//  Example 2:
//  Input: nums = [1,1]
//  Output: [2]
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 105
//  1 <= nums[i] <= n
//  
//   
//  Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//  

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> cache(nums.begin(), nums.end());
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (cache.count(i) == 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int pos = abs(nums[i]) - 1;
            if (nums[pos] > 0) {
                nums[pos] = -nums[pos];
            }
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            int pos = i - 1;
            if (nums[pos] > 0) {
                res.push_back(i);
            }
        }

        return res;
    }
};