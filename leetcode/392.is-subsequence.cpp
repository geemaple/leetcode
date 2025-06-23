//  Tag: Two Pointers, String, Dynamic Programming
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//  A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//   
//  Example 1:
//  Input: s = "abc", t = "ahbgdc"
//  Output: true
//  Example 2:
//  Input: s = "axc", t = "ahbgdc"
//  Output: false
//  
//   
//  Constraints:
//  
//  0 <= s.length <= 100
//  0 <= t.length <= 104
//  s and t consist only of lowercase English letters.
//  
//   
//  Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i += 1;
            }
            j += 1;
        }   
        return i == n;
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(m + 1, 0);
        int match = 0;
        for (int i = 1; i < m + 1; i++) {
            if (match < n && t[i - 1] == s[match]) {
                dp[i] = dp[i - 1] + 1;
                match += 1;
            } else {
                dp[i] = dp[i - 1];
            }
        }

        return dp.back() == n;
    }
};


class Solution {
public:
    vector<bool> batchIsSubsequence(string t, vector<string>& sList) {
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < t.size(); ++i) {
            pos[t[i]].push_back(i);
        }

        auto isSubsequence = [&](const string& s) {
            int prev = -1;
            for (char c : s) {
                if (pos.find(c) == pos.end()) {
                    return false;
                }

                const vector<int>& indices = pos[c];
                auto it = upper_bound(indices.begin(), indices.end(), prev);
                if (it == indices.end()) {
                    return false;
                }
                prev = *it;
            }
            return true;
        };

        vector<bool> result;
        for (const string& s : sList) {
            result.push_back(isSubsequence(s));
        }
        return result;
    }
};