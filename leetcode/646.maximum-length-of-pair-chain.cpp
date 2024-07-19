//  Tag: Array, Dynamic Programming, Greedy, Sorting
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
//  A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
//  Return the length longest chain which can be formed.
//  You do not need to use up all the given intervals. You can select pairs in any order.
//   
//  Example 1:
//  
//  Input: pairs = [[1,2],[2,3],[3,4]]
//  Output: 2
//  Explanation: The longest chain is [1,2] -> [3,4].
//  
//  Example 2:
//  
//  Input: pairs = [[1,2],[7,8],[4,5]]
//  Output: 3
//  Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
//  
//   
//  Constraints:
//  
//  n == pairs.length
//  1 <= n <= 1000
//  -1000 <= lefti < righti <= 1000
//  
//  

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());

        vector<vector<int>> dp;

        for (auto pair : pairs) {
            auto it = lower_bound(dp.begin(), dp.end(), pair, [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[0];
            });

            if (it == dp.end()) {
                dp.push_back(pair);
            } else {
                if ((*it)[1] > pair[1]) {
                    *it = pair;
                }
            }
        }

        return dp.size();
    }
};

#include <vector>
#include <algorithm>

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int>&b) {
            return a[1] < b[1];
        });

        int res = 1;
        int cur = pairs[0][1];

        for (int i = 1; i < n; i++) {
            if (pairs[i][0] > cur) {
                res += 1;
                cur = pairs[i][1];
            }
        }
        return res;
    }
};