//  Tag: Two Pointers, String, Dynamic Programming
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: DP Slow

//  Given a string s, return the number of palindromic substrings in it.
//  A string is a palindrome when it reads the same backward as forward.
//  A substring is a contiguous sequence of characters within the string.
//   
//  Example 1:
//  
//  Input: s = "abc"
//  Output: 3
//  Explanation: Three palindromic strings: "a", "b", "c".
//  
//  Example 2:
//  
//  Input: s = "aaa"
//  Output: 6
//  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 1000
//  s consists of lowercase English letters.
//  
//  

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += expand(s, i, i);
            res += expand(s, i, i + 1);
        }
        return res;
    }

    int expand(string &s, int l, int r) {
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            res += 1;
        }

        for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            dp[i - 1][i] = true;
            res += 1;
        }
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = l + i - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res += 1;
                } 
            }
        }
        return res;
    }
};