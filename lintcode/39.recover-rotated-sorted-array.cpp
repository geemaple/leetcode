//  Category: Array, Sort, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: Rotated

//  Given a **rotated** sorted array, return it to sorted array in-place.（Ascending）
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  array = [4,5,1,2,3]
//  ``` 
//  Output:  
//  ``` 
//  [1,2,3,4,5]
//  ``` 
//  Explanation:  
//  
//  Restore the rotated sorted array.
//  
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  array = [6,8,9,1,2]
//  ``` 
//  Output:  
//  ``` 
//  [1,2,6,8,9]
//  ``` 
//  Explanation:  
//  
//  Restore the rotated sorted array.
//  
//  What is rotated array?
//  
//  - For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3]

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int low = findMin(nums);
        if (low > 0) {
            reverse(nums, 0, low - 1);
            reverse(nums, low, nums.size() - 1);
            reverse(nums, 0, nums.size() - 1);
        }
    }

    void reverse(vector<int> &nums, int start, int end) {
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;

            start++;
            end--;
        }
    }

    int findMin(vector<int> &nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == nums[end]) {
                end--;
                continue;
            }

            if (nums[mid] < nums[end]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};