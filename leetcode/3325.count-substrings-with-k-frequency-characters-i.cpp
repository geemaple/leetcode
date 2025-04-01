//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
//   
//  Example 1:
//  
//  Input: s = "abacb", k = 2
//  Output: 4
//  Explanation:
//  The valid substrings are:
//  
//  "aba" (character 'a' appears 2 times).
//  "abac" (character 'a' appears 2 times).
//  "abacb" (character 'a' appears 2 times).
//  "bacb" (character 'b' appears 2 times).
//  
//  
//  Example 2:
//  
//  Input: s = "abcde", k = 1
//  Output: 15
//  Explanation:
//  All substrings are valid because every character appears at least once.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 3000
//  1 <= k <= s.length
//  s consists only of lowercase English letters.
//  
//  

class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> counter(26, 0);
        int i = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j] - 'a'] += 1;
            while (counter[s[j] - 'a'] >= k) {
                res += n - j;
                counter[s[i] - 'a'] -= 1;
                i += 1;
            }
        }
        return res;
    }
};