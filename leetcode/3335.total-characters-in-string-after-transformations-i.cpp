//  Tag: Hash Table, Math, String, Dynamic Programming, Counting
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/QGsDIA8qaOE

//  You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
//  
//  If the character is 'z', replace it with the string "ab".
//  Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
//  
//  Return the length of the resulting string after exactly t transformations.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: s = "abcyy", t = 2
//  Output: 7
//  Explanation:
//  
//  First Transformation (t = 1):
//  
//  	
//  'a' becomes 'b'
//  'b' becomes 'c'
//  'c' becomes 'd'
//  'y' becomes 'z'
//  'y' becomes 'z'
//  String after the first transformation: "bcdzz"
//  
//  
//  Second Transformation (t = 2):
//  	
//  'b' becomes 'c'
//  'c' becomes 'd'
//  'd' becomes 'e'
//  'z' becomes "ab"
//  'z' becomes "ab"
//  String after the second transformation: "cdeabab"
//  
//  
//  Final Length of the string: The string is "cdeabab", which has 7 characters.
//  
//  
//  Example 2:
//  
//  Input: s = "azbk", t = 1
//  Output: 5
//  Explanation:
//  
//  First Transformation (t = 1):
//  
//  	
//  'a' becomes 'b'
//  'z' becomes "ab"
//  'b' becomes 'c'
//  'k' becomes 'l'
//  String after the first transformation: "babcl"
//  
//  
//  Final Length of the string: The string is "babcl", which has 5 characters.
//  
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists only of lowercase English letters.
//  1 <= t <= 105
//  
//  

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<int> counter(26, 0);
        for (auto &x: s) {
            counter[x - 'a'] += 1;
        }

        for (int i = 0; i < t; i++) {
            vector<int> tmp(26, 0);
            for (int j = 0; j < 26; j++) {
                tmp[(j + 1) % 26] = counter[j];
            }
            tmp[1] = (tmp[0] * 1LL + tmp[1]) % MOD;
            counter = tmp;
        }

        return accumulate(counter.begin(), counter.end(), 0, [MOD](int sum, int value) {
            return (sum + value) % MOD;
        });
    }
};

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9 + 7;
        vector<int> dp(26 + t, 0);
        for (int i = 0; i < 26; i++) {
            dp[i] = 1;
        }

        for (int i = 26; i < 26 + t; i++) {
            dp[i] = (dp[i - 26] + dp[i - 26 + 1]) % MOD;
        }

        int res = 0;
        for (auto &c: s) {
            res = (res + dp[c - 'a' + t] * 1LL) % MOD;
        }

        return res;
    }
};