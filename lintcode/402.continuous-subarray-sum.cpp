//  Tag: Prefix Sum Array, Array
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array, find a continuous subarray where the sum of numbers is the biggest.
//  Your code should return the index of the first number and the index of the last number.
//  (If their are duplicate answer, return the minimum one in lexicographical order)
//  
//  **Example 1:**
//  
//  ```
//  Input: [-3, 1, 3, -3, 4]
//  Output: [1, 4]
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: [0, 1, 0, 1]
//  Output: [0, 3]
//  Explanation: The minimum one in lexicographical order.
//  ```
//  
//  

class Solution {
public:
    /**
     * @param a: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &a) {
        // write your code here
        int n = a.size();
        vector<int> prefix(n + 1, 0);
        int l = 0;
        int r = 0;
        int min_index = 0;
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + a[i];
            if (prefix[i + 1] - prefix[min_index] > prefix[r + 1] - prefix[l]) {
                l = min_index;
                r = i;
            }

            if (prefix[min_index] > prefix[i + 1]) {
                min_index = i + 1;
            }
        }
        return vector<int> {l, r};
    }
};