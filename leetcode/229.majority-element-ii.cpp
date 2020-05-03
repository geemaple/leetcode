/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (34.61%)
 * Total Accepted:    132.5K
 * Total Submissions: 382.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times.
 * 
 * Note: The algorithm should run in linear time and in O(1) space.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: [3]
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,3,3,2,2,2]
 * Output: [1,2]
 * 
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int candidate1 = 0;
        int candidate2 = 1;
        int count1 = 0;
        int count2 = 0;

        int size = (int)nums.size();

        for (int& n : nums) {
            if (candidate1 == n) {
                count1 ++;
            } else if (candidate2 == n) {
                count2 ++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = n;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }
        
        vector<int> res;
        count1 = count2 = 0;
        for (int& m : nums) {
            if (m == candidate1) count1++;
            if (m == candidate2) count2++;
        }
        if (count1 > size / 3) {
            res.push_back(candidate1);
        }
        if (count2 > size / 3) {
            res.push_back(candidate2);
        }

        return res;
    }
};