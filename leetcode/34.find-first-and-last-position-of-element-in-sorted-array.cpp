//  Category: Array, Binary Search
//  Time: O(logN)
//  Space: O(1)
//  Ref: https://youtu.be/y6OT8heV-30
//  Note: std::lower_bound

//  Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
//  If target is not found in the array, return [-1, -1].
//  You must write an algorithm with O(log n) runtime complexity.
//   
//  Example 1:
//  Input: nums = [5,7,7,8,8,10], target = 8
//  Output: [3,4]
//  Example 2:
//  Input: nums = [5,7,7,8,8,10], target = 6
//  Output: [-1,-1]
//  Example 3:
//  Input: nums = [], target = 0
//  Output: [-1,-1]
//  
//   
//  Constraints:
//  
//  0 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  nums is a non-decreasing array.
//  -109 <= target <= 109
//  
//  

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = lower_bound(nums, target);
        if (first == nums.size() || nums[first] != target) {
            return vector<int>{-1, -1};
        }
        int last = lower_bound(nums, target + 1) - 1;
        return vector<int>{first, last};
    }

    int lower_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return start;
    }
};