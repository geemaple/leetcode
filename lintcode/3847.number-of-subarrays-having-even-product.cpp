//  Tag: Array
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-2495
//  Note: -

//  Given an array of integers `nums`, return **the number of subarrays of `nums` having even products.**
//  
//  Example 1:
//  
//  ```
//  Input:
//  nums = [9, 6, 7, 13]
//  Output:
//  6
//  Explanation:
//  [9, 6] The product is 54
//  [9, 6, 7] The product is 378
//  [9, 6, 7, 13] The product is 4914
//  [6] The product is 6
//  [6, 7] The product is 42
//  [6, 7, 13] The product is 546
//  ```
//  
//  Example 2:
//  
//  ```
//  Input:
//  nums = [1, 3, 5, 7, 9]
//  Output:
//  0
//  Explanation:
//  There are no subarrays whose product is an even number
//  ```
//  
//  - $1 \leq nums.length \leq 10^5$
//  - $1 \leq nums[i] \leq 10^5$

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: Number of subarrays having even product
     */
    long long evenProduct(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int count = 0;
        long long res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            count += (nums[j] % 2 == 0);
            while (count) {
                res += n - j;
                count -= (nums[i] % 2 == 0);
                i += 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    /**
     * @param nums: An integer array
     * @return: Number of subarrays having even product
     */
    long long evenProduct(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        long long res = n * (n + 1LL) / 2;
        long long odd = 0;

        for (int i = 0; i < n; i++) {
            odd = (nums[i] % 2 == 1) ? odd + 1 : 0;
            res -= odd;
        }
        return res;
    }
};