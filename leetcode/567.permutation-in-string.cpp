//  Tag: Hash Table, Two Pointers, String, Sliding Window
//  Time: O(N+M)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
//  In other words, return true if one of s1's permutations is the substring of s2.
//   
//  Example 1:
//  
//  Input: s1 = "ab", s2 = "eidbaooo"
//  Output: true
//  Explanation: s2 contains one permutation of s1 ("ba").
//  
//  Example 2:
//  
//  Input: s1 = "ab", s2 = "eidboaoo"
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= s1.length, s2.length <= 104
//  s1 and s2 consist of lowercase English letters.
//  
//  

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> counter;
        for (char x: s1) {
            counter[x] += 1;
        }

        int hit = 0;
        int j = 0;
        for (int i = 0; i < s2.size(); i++) {
            if (counter.count(s2[i]) > 0) {
                counter[s2[i]] -= 1;
                if (counter[s2[i]] >= 0) {
                    hit += 1;
                }
            }
            
            if (i >= s1.size() - 1) {
                if (hit == s1.size()) {
                    return true;
                }

                if (counter.count(s2[j]) > 0) {
                    counter[s2[j]] += 1;
                    if (counter[s2[j]] > 0) {
                        hit -= 1;
                    }
                }

                j += 1;
            }
        }

        return false;
    }
};