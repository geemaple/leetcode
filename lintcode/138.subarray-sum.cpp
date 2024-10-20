//  Tag: Hash Table, Prefix Sum Array, Array
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array, find a subarray where the sum of numbers is **zero**.
//  Your code should return the index of the first number and the index of the last number.
//  
//  **Example 1:**
//  
//  ```
//  Input:  [-3, 1, 2, -3, 4]
//  Output: [0, 2] or [1, 3].
//  Explanation: return anyone that the sum is 0.
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input:  [-3, 1, -4, 2, -3, 4]
//  Output: [1,5]	
//  ```
//  
//  There is at least one subarray that it's sum equals to zero.

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int pre = 0;
        unordered_map<int, int> table;
        table[pre] = 0;
        for (int i = 1; i <= n; i++) {
            pre += nums[i - 1];
            if (table.count(pre) > 0) {
                return vector<int>{table[pre], i - 1};
            } else {
                table[pre] = i;
            }
        }

        return vector<int>{-1, -1};
    }
};