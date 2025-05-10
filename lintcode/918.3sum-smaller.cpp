//  Tag: Opposite Direction Two Pointers, Enumerate, Two Pointers, Array
//  Time: O(N^2)
//  Space: O(1)
//  Ref: Leetcode-259
//  Note: -

//  Given an array of `n` integers nums and a `target`, find the number of index triplets `i, j, k` with `0 <= i < j < k < n` that satisfy the condition `nums[i] + nums[j] + nums[k] < target`.
//  
//  **Example1**
//  
//  ```
//  Input:  nums = [-2,0,1,3], target = 2
//  Output: 2
//  Explanation:
//  Because there are two triplets which sums are less than 2:
//  [-2, 0, 1]
//  [-2, 0, 3]
//  ```
//  
//  **Example2**
//  
//  ```
//  Input: nums = [-2,0,-1,3], target = 2
//  Output: 3
//  Explanation:
//  Because there are three triplets which sums are less than 2:
//  [-2, 0, -1]
//  [-2, 0, 3]
//  [-2, -1, 3]
//  ```
//  
//  

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] < target) {
                    res += r - l;
                    l += 1;
                } else {
                    r -= 1;
                }
            }
        }
        return res;
    }
};