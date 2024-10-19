//  Tag: String, Dynamic Programming
//  Time: O(N^4)
//  Space: O(N^3)
//  Ref: -
//  Note: -

//  We can scramble a string s to get a string t using the following algorithm:
//  
//  If the length of the string is 1, stop.
//  If the length of the string is > 1, do the following:
//  	
//  Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
//  Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
//  Apply step 1 recursively on each of the two substrings x and y.
//  
//  
//  
//  Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
//   
//  Example 1:
//  
//  Input: s1 = "great", s2 = "rgeat"
//  Output: true
//  Explanation: One possible scenario applied on s1 is:
//  "great" --> "gr/eat" // divide at random index.
//  "gr/eat" --> "gr/eat" // random decision is not to swap the two substrings and keep them in order.
//  "gr/eat" --> "g/r / e/at" // apply the same algorithm recursively on both substrings. divide at random index each of them.
//  "g/r / e/at" --> "r/g / e/at" // random decision was to swap the first substring and to keep the second substring in the same order.
//  "r/g / e/at" --> "r/g / e/ a/t" // again apply the algorithm recursively, divide "at" to "a/t".
//  "r/g / e/ a/t" --> "r/g / e/ a/t" // random decision is to keep both substrings in the same order.
//  The algorithm stops now, and the result string is "rgeat" which is s2.
//  As one possible scenario led s1 to be scrambled to s2, we return true.
//  
//  Example 2:
//  
//  Input: s1 = "abcde", s2 = "caebd"
//  Output: false
//  
//  Example 3:
//  
//  Input: s1 = "a", s2 = "a"
//  Output: true
//  
//   
//  Constraints:
//  
//  s1.length == s2.length
//  1 <= s1.length <= 30
//  s1 and s2 consist of lowercase English letters.
//  
//  

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1, false)));

        for (int l = 1; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                for (int j = 0; j <= n - l; j++) {
                    if (l == 1) {
                        dp[i][j][l] = (s1[i] == s2[j]);
                    } else {
                        for (int k = 1; k < l; k++) {
                            if (dp[i][j][k] && dp[i + k][j + k][l - k]) {
                                dp[i][j][l] = true;
                                break;
                            }

                            if (dp[i][j + l - k][k] && dp[i + k][j][l - k]) {
                                dp[i][j][l] = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0][n];
    }
};

class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> cache;
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }

        if (sorted(s1) != sorted(s2)) {
            return false;
        }
        
        if (cache.count(s1) > 0 && cache[s1].count(s2) > 0) {
            return cache[s1][s2];
        }
        
        int n = s1.size();
        for (int k = 1; k < n; k++) {
            if (isScramble(s1.substr(0, k), s2.substr(0, k)) && isScramble(s1.substr(k, n - k), s2.substr(k, n - k))) {
                cache[s1][s2] = true;
                return cache[s1][s2];
            }
            
            if (isScramble(s1.substr(0, k), s2.substr(n - k, k)) && isScramble(s1.substr(k, n - k), s2.substr(0, n - k))) {
                cache[s1][s2] = true;
                return cache[s1][s2];
            }
        }
        
        cache[s1][s2] = false;
        return cache[s1][s2];
    }
    
    string sorted(string &s) {
        string sorted = s;
        sort(sorted.begin(), sorted.end());
        return sorted;
    }
};