//  Tag: Sliding Window, Array
//  Time: O(N)
//  Space: O(K)
//  Ref: Leetcode-1852
//  Note: -

//  Given an array of integers `nums` and a positive integer `k`, construct an array `res` of length `n - k + 1` whose `i`th element `res[i]` is the number of distinct element values in each subarray of length `k` `nums[i:i + k-1] = [nums[i], nums[i + 1], ...
//  , nums[i + k - 1]]` the number of varieties of different element values.
//  
//  Returns the result array `res`.
//  
//  Example 1:
//  ```
//  Input:
//  nums = [1, 2, 3, 2, 2, 1, 3]
//  k = 3
//  Output:
//  [3, 2, 2, 2, 3]
//  Explanation:
//  A total of 5 subarrays are formed, where:
//  nums[0:2] = [1, 2, 3]，therefore res[0] = 3
//  nums[1:3] = [2, 3, 2]，therefore res[1] = 2
//  nums[2:4] = [3, 2, 2]，therefore res[2] = 2
//  nums[3:5] = [2, 2, 1]，therefore res[3] = 2
//  nums[4:6] = [2, 1, 3]，therefore res[4] = 3
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  nums = [1, 1, 1, 2, 3]
//  k = 3
//  Output:
//  [1, 2, 3]
//  ```
//  
//  $1 \leq k \leq nums.length \leq 10^5$
//  $1 \leq nums[i] \leq 10^5$

class Solution {
public:
    /**
     * @param nums: An integer array
     * @param k: Size of subarray
     * @return: Count of different numbers in the subarray
     */
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        // write your code here
        int n = nums.size();
        unordered_map<int, int> counter;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            counter[nums[i]] += 1;
            if (i >= k - 1) {
                res.push_back(counter.size());
                int j = i - k + 1;
                counter[nums[j]] -= 1;
                if (counter[nums[j]] == 0) {
                    counter.erase(nums[j]);
                }
            }
        }
        return res;
    }
};