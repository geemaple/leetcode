//  Tag: Array, Two Pointers, Stack, Greedy, Sorting, Monotonic Stack
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
//  Return the shortest such subarray and output its length.
//   
//  Example 1:
//  
//  Input: nums = [2,6,4,8,10,9,15]
//  Output: 5
//  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,4]
//  Output: 0
//  
//  Example 3:
//  
//  Input: nums = [1]
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 104
//  -105 <= nums[i] <= 105
//  
//   
//  Follow up: Can you solve it in O(n) time complexity?

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int r = -1;
        int biggest = nums[0];
        for (int i = 1; i < n; ++i) {
            if (biggest > nums[i]) {
                r = i;
            } else {
                biggest = nums[i];
            }
        }

        int l = 0;
        int smallest = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (smallest < nums[i]) {
                l = i;
            } else {
                smallest = nums[i];
            }
        }

        return r - l + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        int l = n - 1;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
                l = min(l, s.empty() ? -1 : s.top());
            }
            s.push(i);
        }

        if (l == n - 1) {
            return 0;
        }

        while (!s.empty()) s.pop();
        int r = 0;

        for (int i = n - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
                r = max(r, s.empty() ? n : s.top());
            }
            s.push(i);
        }

        return r - l - 1;
    }
};