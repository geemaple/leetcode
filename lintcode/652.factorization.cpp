//  Tag: Depth First Search/DFS
//  Time: O(2^K)
//  Space: O(LogN)
//  Ref: -
//  Note: -

//  A non-negative numbers can be regarded as product of its factors.
//  Write a function that takes an integer n and return all possible combinations of its factors.
//  
//  **Example1**
//  ```
//  Input: 8
//  Output: [[2,2,2],[2,4]]
//  Explanation:
//  8 = 2 x 2 x 2 = 2 x 4
//  ```
//  **Example2**
//  ```
//  Input: 1
//  Output: []
//  ```
//  
//  - Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
//  - The solution set must not contain duplicate combination.

class Solution {
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     *          we will sort your return value in output
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<int> ans;
        vector<vector<int>> res;
        helper(2, n, ans, res);
        return res;
    }

    void helper(int start, int n, vector<int> &ans, vector<vector<int>> &res) {
        if (ans.size() > 0) {
            ans.push_back(n);
            res.push_back(ans);
            ans.pop_back();
        }

        for (int k = start; k < n; k++) {
            if (n / k < k) {
                break;
            }
            if (n % k == 0) {
                ans.push_back(k);
                helper(k, n / k, ans, res);
                ans.pop_back();
            }
        }

    }
};