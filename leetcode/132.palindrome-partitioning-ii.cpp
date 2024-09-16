//  Tag: String, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  Given a string s, partition s such that every substring of the partition is a palindrome.
//  Return the minimum cuts needed for a palindrome partitioning of s.
//   
//  Example 1:
//  
//  Input: s = "aab"
//  Output: 1
//  Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
//  
//  Example 2:
//  
//  Input: s = "a"
//  Output: 0
//  
//  Example 3:
//  
//  Input: s = "ab"
//  Output: 1
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 2000
//  s consists of lowercase English letters only.
//  
//  

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> is_palindrome(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            expand(s, i, i, is_palindrome);
            expand(s, i, i + 1, is_palindrome);
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (is_palindrome[j][i - 1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n] - 1;
    }

    void expand(string &s, int left, int right, vector<vector<bool>> &is_palindrome) {
        while (left >=0 && right < s.size() && s[left] == s[right]) {
            is_palindrome[left][right] = true;
            left--;
            right++;
        }
    }
};