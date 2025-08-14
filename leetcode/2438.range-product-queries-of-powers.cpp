//  Tag: Array, Bit Manipulation, Prefix Sum
//  Time: O(M)
//  Space: O(K)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/1YdNrNnoMHA

//  Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
//  You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
//  Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: n = 15, queries = [[0,1],[2,2],[0,3]]
//  Output: [2,4,64]
//  Explanation:
//  For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
//  Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
//  Answer to 2nd query: powers[2] = 4.
//  Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
//  Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
//  
//  Example 2:
//  
//  Input: n = 2, queries = [[0,0]]
//  Output: [2]
//  Explanation:
//  For n = 2, powers = [2].
//  The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.
//  
//   
//  Constraints:
//  
//  1 <= n <= 109
//  1 <= queries.length <= 105
//  0 <= starti <= endi < powers.length
//  
//  

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                powers.push_back(1 << i);
            }
        }
        vector<int> res;
        for (auto &q: queries) {
            int l = q[0];
            int r = q[1];
            long long ans = 1;
            for (int i = l; i <= r; i++) {
                ans = (ans * powers[i]) % mod;
            }
            res.push_back(ans);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;
        while (n > 0) {
            int x = n & (-n);
            powers.push_back(x);
            n = n & (n - 1); // n = n ^ x;
        }
        vector<int> res;
        for (auto &q: queries) {
            int l = q[0];
            int r = q[1];
            long long ans = 1;
            for (int i = l; i <= r; i++) {
                ans = (ans * powers[i]) % mod;
            }
            res.push_back(ans);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;
        for (int i = 0; i < 32; i++) {
            if ((n & (1 << i)) != 0) {
                powers.push_back(1 << i);
            }
        }
        int k = powers.size();
        vector<int> prefix(k + 1, 1);
        vector<int> revert(k + 1, 0);

        for (int i = 0; i < k; i++) {
            prefix[i + 1] = (1LL * prefix[i] * powers[i]) % mod;
        }

        revert[k] = pow(prefix[k], mod - 2, mod);
        for (int i = k - 1; i >= 0; i--) {
            revert[i] = (1LL * powers[i] * revert[i + 1]) % mod;
        }

        vector<int> res;
        for (auto &q: queries) {
            int l = q[0];
            int r = q[1];
            int ans = (1LL * prefix[r + 1] * revert[l]) % mod;
            res.push_back(ans);
        }
        return res;
    }

    int pow(int n, int p, int mod) {
        int res = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                res = (1LL * res * n) % mod;
            }
            n = (1LL * n * n) % mod;
            p = p / 2;
        }
        return res;
    }
};