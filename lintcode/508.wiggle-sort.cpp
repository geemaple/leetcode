//  Tag: Quick Select, Sort
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-280
//  Note: -

//  Given an unsorted array `nums`, reorder it **in-place** such that 
//  
//  ```
//  nums[0] <= nums[1] >= nums[2] <= nums[3]....
//  ```
//  
//  There may have multiple answers for a question, **you only need to consider one of the possibilities**.
//  
//  **Example 1:**
//  
//  ```
//  Input: [3, 5, 2, 1, 6, 4]
//  Output: [1, 6, 2, 5, 3, 4]
//  Explanation: This question may have multiple answers, and [2, 6, 1, 5, 3, 4] is also ok.
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: [1, 2, 3, 4]
//  Output: [1, 4, 2, 3]
//  ```
//  
//  Please sort the array in place and do not define additional arrays.

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (i & 1 == 1) {
                if (nums[i] < nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            } else {
                if (nums[i] > nums[i - 1]) {
                    swap(nums[i], nums[i - 1]);
                }
            }
        }
    }
};