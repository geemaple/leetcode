//  Tag: Dynamic Programming/DP, Coordinate DP
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: Leetcode-265

//  There are a row of `n` houses, each house can be painted with one of the `k` colors.
//  The cost of painting each house with a certain color is different.
//  You have to paint all the houses such that no two adjacent houses have the same color.
//  
//  The cost of painting each house with a certain color is represented by a `n` x `k` cost matrix.
//  For example, `costs[0][0]` is the cost of painting house `0` with color `0`; `costs[1][2]` is the cost of painting house `1` with color `2`, and so on...
//  Find the minimum cost to paint all houses.
//  
//  **Example 1**
//  
//  ```plain
//  Input:
//  costs = [[14,2,11],[11,14,5],[14,3,10]]
//  Output: 10
//  Explanation:
//  The three house use color [1,2,1] for each house. The total cost is 10.
//  ```
//  
//  **Example 2**
//  
//  ```plain
//  Input:
//  costs = [[5]]
//  Output: 5
//  Explanation:
//  There is only one color and one house.
//  ```
//  
//  All costs are positive integers.

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if (costs.size() == 0) {
            return 0;
        }

        int n = costs.size();
        int m = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                int cost = INT_MAX;
                for (int k = 0; k < m; k++) {
                    if (i == 1 || j != k) {
                        cost = min(cost, dp[i - 1][k] + costs[i - 1][j]);
                    }
                }
                dp[i][j] = cost;
            }

        }

        return *min_element(dp[n].begin(), dp[n].end());
    }
};

class Solution {
public:
    /**
     * @param costs: n x k cost matrix
     * @return: an integer, the minimum cost to paint all houses
     */
    int minCostII(vector<vector<int>> &costs) {
        // write your code here
        if (costs.size() == 0) {
            return 0;
        }

        int n = costs.size();
        int m = costs[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m, 0));

        for (int i = 1; i <= n; i++) {

            int pre_min1 = INT_MAX;
            int pre_min2 = INT_MAX;
            for (int j = 0; j < m; j++) { 
                if (dp[i - 1][j] < pre_min1) {
                    pre_min2 = pre_min1;
                    pre_min1 = dp[i - 1][j];
                } else if (dp[i - 1][j] < pre_min2) {
                    pre_min2 = dp[i - 1][j];
                }
            }

            for (int j = 0; j < m; j++) {
                int pre = (i > 1 && dp[i - 1][j] == pre_min1) ? pre_min2 : pre_min1;
                dp[i][j] = pre + costs[i - 1][j];
            }

        }

        return *min_element(dp[n].begin(), dp[n].end());
    }
};