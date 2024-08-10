//  Tag: Two Pointers, String, Dynamic Programming
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s, return the longest palindromic substring in s.
//   
//  Example 1:
//  
//  Input: s = "babad"
//  Output: "bab"
//  Explanation: "aba" is also a valid answer.
//  
//  Example 2:
//  
//  Input: s = "cbbd"
//  Output: "bb"
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 1000
//  s consist of only digits and English letters.
//  
//  

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int length = 1;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) {
                dp[i - 1][i] = true;
                start = i - 1;
                length = 2;
            }
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = l + i - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (length < j - i + 1) {
                        length = j - i + 1;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, length);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            string tmp = expand(s, i, i);
            if (tmp.size() > res.size()) {
                res = tmp;
            }
            tmp = expand(s, i, i + 1);
            if (tmp.size() > res.size()) {
                res = tmp;
            }
        }

        return res;
    }

    string expand(string &s, int l, int r) {
        while (l >=0 && r < s.size()) {
            if (s[l] == s[r]) {
                l --;
                r ++;
            } else {
                break;
            }
        }
        int start = l + 1;
        int length = r - start;
        return s.substr(start, length);
    }
};

class Solution {
public:
    string longestPalindrome(string s) {
        string t = buildString(s);
        int n = t.size();
        vector<int> p(n, 0);
        int center = 0;
        int right_x = 0;

        for (int i = 0; i < n; i++) {
            int mirror_j = 2 * center - i;
            if (i < right_x) {
                p[i] = min(right_x - i, p[mirror_j]);
            }

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }

            if (right_x < i + p[i]) {
                center = i;
                right_x = i + p[i];
            }
        }


        int max_center = 0;
        int max_r = 0;
        for (int i = 0; i < n; i++) {
            if (max_r < p[i]) {
                max_r = p[i];
                max_center = i;
            }
        }

        int start = (max_center - max_r) / 2;
        return s.substr(start, max_r);

    }

    string buildString(string s) {
        string t = "#";
        for (auto x: s) {
            t += x;
            t += '#';
        }
        return t;
    }
};