//  Tag: Array, Hash Table, Divide and Conquer, Sorting, Counting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array nums of size n, return the majority element.
//  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//   
//  Example 1:
//  Input: nums = [3,2,3]
//  Output: 3
//  Example 2:
//  Input: nums = [2,2,1,1,1,2,2]
//  Output: 2
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 5 * 104
//  -109 <= nums[i] <= 109
//  
//   
//  Follow-up: Could you solve the problem in linear time and in O(1) space?

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int count = 0;
        for (auto x: nums) {
            if (count == 0) {
                res = x;
            }

            if (res == x) {
                count++;
            } else {
                count--;
            }
        }

        return res;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (auto x: nums) {
            counter[x] += 1;
        }

        for (auto it = counter.begin(); it != counter.end(); it++) {
            if (it->second > n / 2) {
                return it->first;
            }
        }

        return -1;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};