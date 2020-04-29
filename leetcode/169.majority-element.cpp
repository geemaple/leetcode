/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (55.91%)
 * Total Accepted:    542.6K
 * Total Submissions: 960.7K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */
// O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int candidate = 0;

        for (int i = 0; i < nums.size(); i++) {
            
            if (counter == 0) {
                candidate = nums[i];
            }

            if (candidate == nums[i]) {
                counter += 1;
            } else {
                counter -= 1;
            }
        }
        
        return candidate;
    }
};
