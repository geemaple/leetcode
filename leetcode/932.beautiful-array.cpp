//  Tag: Array, Math, Divide and Conquer
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: dp

//  An array nums of length n is beautiful if:
//  
//  nums is a permutation of the integers in the range [1, n].
//  For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//  
//  Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
//   
//  Example 1:
//  Input: n = 4
//  Output: [2,1,4,3]
//  Example 2:
//  Input: n = 5
//  Output: [3,1,2,5,4]
//  
//   
//  Constraints:
//  
//  1 <= n <= 1000
//  
//  

class Solution {
public:
    unordered_map<int, vector<int>> cache;
    vector<int> beautifulArray(int n) {
        if (n == 1) {
            return vector<int>{1};
        }

        if (cache.count(n)) {
            return cache[n];
        }

        vector<int> even = beautifulArray(n / 2);
        vector<int> odd = beautifulArray(n - n / 2);

        vector<int> res;
        for (auto k: even) {
            res.push_back(2 * k);
        }

        for (auto k: odd) {
            res.push_back(2 * k - 1);
        }

        cache[n] = res;
        return res;
    }
};

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<vector<int>> dp(n + 1);
        dp[1] = {1};

        for (int i = 2; i <= n; i++) {
            int even = i / 2;
            int odd = i - i / 2;

            for (auto k : dp[even]) {
                dp[i].push_back(2 * k);
            }

            for (auto k : dp[odd]) {
                dp[i].push_back(2 * k - 1);
            }
        }

        return dp[n];
    }
};

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> res = {1};

        while (res.size() < n) {
            vector<int> tmp;
            for (auto k: res) {
                if (2 * k <= n) {
                    tmp.push_back(2 * k);
                }
            }

            for (auto k: res) {
                if (2 * k - 1 <= n) {
                    tmp.push_back(2 * k - 1);
                }
            }

            res = tmp;
        }

        return res;
    }
};