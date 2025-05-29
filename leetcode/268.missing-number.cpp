//  Tag: Array, Hash Table, Math, Binary Search, Bit Manipulation, Sorting, Index Sort
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
//   
//  Example 1:
//  
//  Input: nums = [3,0,1]
//  Output: 2
//  Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.
//  
//  Example 2:
//  
//  Input: nums = [0,1]
//  Output: 2
//  Explanation: n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.
//  
//  Example 3:
//  
//  Input: nums = [9,6,4,2,3,5,7,0,1]
//  Output: 8
//  Explanation: n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 104
//  0 <= nums[i] <= n
//  All the numbers of nums are unique.
//  
//   
//  Follow up: Could you implement a solution using only O(1) extra space complexity and O(n) runtime complexity?
//  

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = res ^ (i + 1) ^ nums[i];
        }

        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = (n + 1) * n / 2;
        for (int i = 0; i < n; i++) {
            res -= nums[i];
        }

        return res;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.insert(nums.begin(), -1);
        int i = 1;
        while (i < nums.size()) {
            int j = nums[i];
            if (j >= 0 && j < nums.size() && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i += 1;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                return i;
            }
        }

        return -1;
    }
};