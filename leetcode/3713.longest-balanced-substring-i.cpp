//  Tag: Hash Table, String, Counting, Enumeration
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given a string s consisting of lowercase English letters.
//  A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
//  Return the length of the longest balanced substring of s.
//   
//  Example 1:
//  
//  Input: s = "abbac"
//  Output: 4
//  Explanation:
//  The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
//  
//  Example 2:
//  
//  Input: s = "zzabccy"
//  Output: 4
//  Explanation:
//  The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​
//  
//  Example 3:
//  
//  Input: s = "aba"
//  Output: 2
//  Explanation:
//  ​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".
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
    int longestBalanced(string s) {
        int n = s.size();
        int result = 0;

        for (int l = 0; l < n; ++l) {
            if (n - l <= result) break;

            vector<int> cnt(26, 0);
            int uniq = 0;
            int maxfreq = 0;

            for (int r = l; r < n; ++r) {

                if (cnt[s[r] - 'a'] == 0) { 
                    uniq++;
                }
                cnt[s[r] - 'a']++;

                if (cnt[s[r] - 'a'] > maxfreq) {
                    maxfreq = cnt[s[r] - 'a'];
                }

                int cur = r - l + 1;
                if (uniq * maxfreq == cur && cur > result) {
                    result = cur;
                }
            }
        }

        return result; 
    }
};