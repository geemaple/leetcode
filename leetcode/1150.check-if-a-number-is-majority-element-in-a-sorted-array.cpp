/*
 * @lc app=leetcode id=1150 lang=cpp
 *
 * [1150] Check If a Number Is Majority Element in a Sorted Array
 *
 * https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/description/
 *
 * algorithms
 * Easy (60.23%)
 * Total Accepted:    10.2K
 * Total Submissions: 17K
 * Testcase Example:  '[2,4,5,5,5,5,5,6,6]\n5'
 *
 * Given an array nums sorted in non-decreasing order, and a number target,
 * return True if and only if target is a majority element.
 * 
 * A majority element is an element that appears more than N/2 times in an
 * array of length N.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,4,5,5,5,5,5,6,6], target = 5
 * Output: true
 * Explanation: 
 * The value 5 appears 5 times and the length of the array is 9.
 * Thus, 5 is a majority element because 5 > 9/2 is true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [10,100,101,101], target = 101
 * Output: false
 * Explanation: 
 * The value 101 appears 2 times and the length of the array is 4.
 * Thus, 101 is not a majority element because 2 > 4/2 is false.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^9
 * 1 <= target <= 10^9
 * 
 * 
 */

// O(logN)
class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        
        int head = headOfElement(nums, target);
        int tail = head + (int)nums.size() / 2;

        return (head >= 0) && (tail < nums.size()) && nums[tail] == target;
    }

    int headOfElement(vector<int>& nums, int target) {
        int start = 0;
        int end = (int)nums.size() - 1;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                end = mid;
            } else if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[start] == target) {
            return start;
        }

        if (nums[end] == target) {
            return end;
        }

        return -1;
    }
};
