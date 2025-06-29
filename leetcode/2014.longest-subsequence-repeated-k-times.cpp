//  Tag: String, Backtracking, Greedy, Counting, Enumeration
//  Time: O(An)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/bsC1C3R6hds

//  You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
//  A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
//  A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
//  
//  For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
//  
//  Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
//   
//  Example 1:
//  
//  
//  Input: s = "letsleetcode", k = 2
//  Output: "let"
//  Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
//  "let" is the lexicographically largest one.
//  
//  Example 2:
//  
//  Input: s = "bb", k = 2
//  Output: "b"
//  Explanation: The longest subsequence repeated 2 times is "b".
//  
//  Example 3:
//  
//  Input: s = "ab", k = 2
//  Output: ""
//  Explanation: There is no subsequence repeated 2 times. Empty string is returned.
//  
//   
//  Constraints:
//  
//  n == s.length
//  2 <= n, k <= 2000
//  2 <= n < k * 8
//  s consists of lowercase English letters.
//  
//  

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> counter(26, 0);
        for (auto &ch: s) {
            counter[ch - 'a'] += 1;
        }
        queue<string> q;
        string res = "";
        string candidates = "";
        for (int i = 0; i < 26; i++) {
            if (counter[i] >= k) {
                string x = string(1, 'a' + i);
                res = x;
                candidates += x;
                q.push(x);
            }
        }

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            for (auto &ch: candidates) {
                string tmp = cur + ch;
                if (check(tmp, s, k)) {
                    res = tmp;
                    q.push(tmp);
                }
            }
        }

        return res;
    }

    bool check(string &c, string &s, int k) {
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < c.size() && s[i] == c[j]) {
                j += 1;
            }

            if (j == c.size() && k > 1) {
                k -= 1;
                j = 0;
            }
        }

        return j == c.size();
    }
};

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        vector<int> counter(26, 0);
        for (auto &ch: s) {
            counter[ch - 'a'] += 1;
        }
        vector<int> used(26, 0);
        string res = "";
        find(counter, used, res, s, k, "");
        return res;
    }

    bool check(string &c, string &s, int k) {
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (j < c.size() && s[i] == c[j]) {
                j += 1;
            }

            if (j == c.size() && k > 1) {
                k -= 1;
                j = 0;
            }
        }

        return j == c.size();
    }

    void find(vector<int> &counter, vector<int> &used, string &res, string &s, int k, string ans) {
        if (res.size() < ans.size() && check(ans, s, k)) {
            res = ans;
        }

        if (ans.size() == s.size() / k) {
            return;
        }

        for (int i = 25; i >= 0; i--) {
            if (counter[i] - used[i] >= k) {
                char x = 'a' + i;
                used[i] += k;   
                find(counter, used, res, s, k, ans + x);
                used[i] -= k;
            }
        }
    }
};