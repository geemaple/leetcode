//  Tag: Array, Hash Table, Sorting, Heap (Priority Queue)
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/tN8cNTRRnVg

//  You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
//  Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.
//   
//  Example 1:
//  
//  Input: nums = [18,43,36,13,7]
//  Output: 54
//  Explanation: The pairs (i, j) that satisfy the conditions are:
//  - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
//  - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
//  So the maximum sum that we can obtain is 54.
//  
//  Example 2:
//  
//  Input: nums = [10,12,19,14]
//  Output: -1
//  Explanation: There are no two numbers that satisfy the conditions, so we return -1.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 109
//  
//  

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> counter;

        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            int digits = 0;
            while (tmp) {
                digits += tmp % 10;
                tmp = tmp / 10;
            }

            if (counter.count(digits) == 0) {
                counter[digits] = {nums[i], -1};
            } else {
                auto &pairs = counter[digits];
                if (nums[i] > pairs[0]) {
                    pairs[1] = pairs[0];
                    pairs[0] = nums[i];
                } else if (nums[i] > pairs[1]) {
                    pairs[1] = nums[i];
                }
            }
        }
        int res = -1;
        for (auto &[digits, pairs]: counter) {
            if (pairs[1] > 0) {
                res = max(res, pairs[0] + pairs[1]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        int res = -1;
        for (int i = 0; i < n; i++) {
            int tmp = nums[i];
            int digits = 0;
            while (tmp) {
                digits += tmp % 10;
                tmp = tmp / 10;
            }

            if (counter.count(digits) == 0) {
                counter[digits] = nums[i];
            } else {
                res = max(res, counter[digits] + nums[i]);
                counter[digits] = max(counter[digits], nums[i]);
            }
        }

        return res;
    }
};