//  Tag: String, Dynamic Programming, Prefix Sum
//  Time: O(NK)
//  Space: O(NK)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/DiQH5HNtQSM

//  Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
//  You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
//  Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: word = "aabbccdd", k = 7
//  Output: 5
//  Explanation:
//  The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
//  
//  Example 2:
//  
//  Input: word = "aabbccdd", k = 8
//  Output: 1
//  Explanation:
//  The only possible string is "aabbccdd".
//  
//  Example 3:
//  
//  Input: word = "aaabbb", k = 3
//  Output: 8
//  
//   
//  Constraints:
//  
//  1 <= word.length <= 5 * 105
//  word consists only of lowercase English letters.
//  1 <= k <= 2000
//  
//  

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int mod = 1e9 + 7;
        int n = word.size();
        vector<int> groups;
        int count = 1;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && word[i] == word[i - 1]) {
                count += 1;
            } else {
                groups.push_back(count);
                res = (res * count) % mod;
                count = 1;
            }
        }
        int m = groups.size();
        if (k <= m) {
            return res;
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(k, 0));
        dp[0][0] = 1;
        vector<long long> prefix(k + 1, 0);
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % mod;
                dp[i][j] = (prefix[j + 1] - prefix[max(0, j - groups[i - 1] + 1)]) % mod;
            }
        }

        for (int j = 0; j < k - m; j++) {
            res = (mod + res - dp[m][j]) % mod;
        }

        return res;
    }
};

class Solution {
public:
    int possibleStringCount(string word, int k) {
        int mod = 1e9 + 7;
        int n = word.size();
        vector<int> groups;
        int count = 1;
        long long res = 1;
        for (int i = 1; i <= n; i++) {
            if (i < n && word[i] == word[i - 1]) {
                count += 1;
            } else {
                groups.push_back(count);
                res = (res * count) % mod;
                count = 1;
            }
        }
        int m = groups.size();
        if (k <= m) {
            return res;
        }

        vector<vector<long long>> dp(m + 1, vector<long long>(k, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < k; j++) {
                for (int c = 0; c < min(j + 1, groups[i - 1]); c++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - c]) % mod;
                }
            }
        }

        for (int j = 0; j < k - m; j++) {
            res = (mod + res - dp[m][j]) % mod;
        }

        return res;
    }
};