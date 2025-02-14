//  Tag: String, Sliding Window
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
//  Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
//   
//  Example 1:
//  
//  Input: s = "abciiidef", k = 3
//  Output: 3
//  Explanation: The substring "iii" contains 3 vowel letters.
//  
//  Example 2:
//  
//  Input: s = "aeiou", k = 2
//  Output: 2
//  Explanation: Any substring of length 2 contains 2 vowels.
//  
//  Example 3:
//  
//  Input: s = "leetcode", k = 3
//  Output: 2
//  Explanation: "lee", "eet" and "ode" contain 2 vowels.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists of lowercase English letters.
//  1 <= k <= s.length
//  
//  

class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int res = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                count += 1;
            }

            if (i >= k - 1) {
                res = max(res, count);
                if (isVowel(s[i - k + 1])) {
                    count -= 1;
                }
            }
        }

        return res;
    }

    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
};