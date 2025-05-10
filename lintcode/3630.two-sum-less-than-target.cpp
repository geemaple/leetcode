//  Tag: Binary Search, Two Pointers, Array
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: Leetcode-1099
//  Note: -

//  Given an array of integers `nums` and an integer `target`, if there exists `i < j` such that `nums[i] + nums[j] < target`, then return **the maximum and  that satisfy this condition**.
//  If no `i, j` satisfying the above condition exists, then `-1` is returned.
//  
//  Example 1:
//  ```
//  Input:
//  nums = [2, 7, 11, 15], target = 24
//  Output:
//  22
//  Explanation:
//  7 + 15 = 22 < 24
//  11 + 15 = 26 > 24
//  22 is the maximum sum that satisfies the condition
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  nums = [3, 5, 1, 9, 7], target = 3
//  Output:
//  -1
//  Explanation:
//  Cannot find two elements whose sum is less than 3
//  ```
//  
//  $1 \leq nums.length \leq 1000$
//  $-1000 \leq nums[i] \leq 1000$
//  $-2000 \leq target \leq 2000$

class Solution {
public:
    /**
     * @param nums: An array of integer
     * @param target: An integer
     * @return: The sum of two numbers smaller than target
     */
    int twoSumLessThanTarget(vector<int> &nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = nums.size() - 1;
        int res = INT_MIN;
        while (l < r) {
            if (nums[l] + nums[r] < target) {
                res = max(res, nums[l] + nums[r]);
                l += 1;
            } else {
                r -= 1;
            }
        }
        return res == INT_MIN ? -1 : res;
    }
};