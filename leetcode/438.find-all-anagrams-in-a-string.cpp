//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//   
//  Example 1:
//  
//  Input: s = "cbaebabacd", p = "abc"
//  Output: [0,6]
//  Explanation:
//  The substring with start index = 0 is "cba", which is an anagram of "abc".
//  The substring with start index = 6 is "bac", which is an anagram of "abc".
//  
//  Example 2:
//  
//  Input: s = "abab", p = "ab"
//  Output: [0,1,2]
//  Explanation:
//  The substring with start index = 0 is "ab", which is an anagram of "ab".
//  The substring with start index = 1 is "ba", which is an anagram of "ab".
//  The substring with start index = 2 is "ab", which is an anagram of "ab".
//  
//   
//  Constraints:
//  
//  1 <= s.length, p.length <= 3 * 104
//  s and p consist of lowercase English letters.
//  
//  

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        unordered_map<char, int> counter;
        for (auto ch: p) {
            counter[ch] += 1;
        }

        int left = p.size();
        vector<int> res;
        int j =0;
        for (int i = 0; i < n; i++) {
            if (counter.count(s[i]) > 0) {
                counter[s[i]]--;
                if (counter[s[i]] >= 0) {
                    left--;
                }
            }

            if (i - j + 1 == p.size()) {
                if (left == 0) {
                    res.push_back(j);
                }

                if (counter.count(s[j]) > 0) {
                    counter[s[j]]++;
                    if (counter[s[j]] > 0) {
                        left++;
                    }
                }

                j++;
            }
        }

        return res;
    }
};