//  Tag: Binary Search on Answer, Binary Search
//  Time: O(Nlog(A/ε))
//  Space: O(N)
//  Ref: Leetcode-644
//  Note: -

//  Given an array with positive and negative numbers, find the `maximum average subarray` which length should be greater or equal to given length `k`.
//  
//  ---
//  
//  Example 1:
//  ```
//  Input:
//  [1,12,-5,-6,50,3]
//  3
//  Output:
//  15.667
//  Explanation:
//   (-6 + 50 + 3) / 3 = 15.667
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  [5]
//  1
//  Output:
//  5.000
//  ```
//  
//  It's guaranteed that the size of the array is greater or equal to *k*.
//  Only unsigned `0` results are allowed to pass when `0` is the return value

class Solution {
public:
    /**
     * @param nums: an array with positive and negative numbers
     * @param k: an integer
     * @return: the maximum average
     */
    double maxAverage(vector<int> &nums, int k) {
        // write your code here
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double mid = (left + right) / 2;
            if (fit(nums, k , mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }

    bool fit(vector<int> &nums, int k, double average) {
        vector<double> prefix = {0};
        for (auto x : nums) {
            prefix.push_back(prefix.back() + x - average);
        }
        double min_prefix = 0;
        for (int i = k; i < prefix.size(); i++) {
            if (prefix[i] - min_prefix >= 0) {
                return true;
            }
            min_prefix = min(min_prefix, prefix[i - k + 1]);
        }

        return false;
    }
};