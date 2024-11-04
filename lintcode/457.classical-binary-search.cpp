//  Tag: Binary Search
//  Time: O(logN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Find any position of a target number in a sorted array.
//  Return `-1` if target does not exist.
//  
//  ---
//   
//  
//  **Example 1:**
//  ```
//  Input: nums = [1,2,2,4,5,5], target = 2
//  Output: 1 or 2
//  ```
//  **Example 2:**
//  ```
//  Input: nums = [1,2,2,4,5,5], target = 6
//  Output: -1
//  ```
//  
//  

class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        // write your code here
        int n = nums.size();
        int start = 0;
        int end = n;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return -1;
    }
};


class Solution {
public:
    /**
     * @param nums: An integer array sorted in ascending order
     * @param target: An integer
     * @return: An integer
     */
    int findPosition(vector<int> &nums, int target) {
        // write your code here


        int n = nums.size();
        if (n == 0) {
            return -1;
        }

        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left] == target ? left : -1;
    }
};