//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s, find the length of the longest substring without repeating characters.
//   
//  Example 1:
//  
//  Input: s = "abcabcbb"
//  Output: 3
//  Explanation: The answer is "abc", with the length of 3.
//  
//  Example 2:
//  
//  Input: s = "bbbbb"
//  Output: 1
//  Explanation: The answer is "b", with the length of 1.
//  
//  Example 3:
//  
//  Input: s = "pwwkew"
//  Output: 3
//  Explanation: The answer is "wke", with the length of 3.
//  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//  
//   
//  Constraints:
//  
//  0 <= s.length <= 5 * 104
//  s consists of English letters, digits, symbols and spaces.
//  
//  

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> cache;
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (cache.count(s[i]) > 0) {
               j = max(j, cache[s[i]] + 1);
            }

            res = max(res, i - j + 1);
            cache[s[i]] = i;
        }

        return res;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> cache;
        int res = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (cache.count(s[i]) > 0) {
                cache.erase(s[j]);
                j++;
            }

            res = max(res, i - j + 1);
            cache.insert(s[i]);
        }

        return res;
    }
};