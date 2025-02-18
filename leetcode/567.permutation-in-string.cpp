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
        int n = s2.size();
        int k = s1.size();
        unordered_map<char, int> counter;
        for (char x: s1) {
            counter[x] += 1;
        }
        
        int hit = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (counter.count(s2[i - k]) > 0) {
                    counter[s2[i - k]] += 1;
                    if (counter[s2[i - k]] >= 1) {
                        hit -= 1;
                    }
                }
            }

            if (counter.count(s2[i]) > 0) {
                counter[s2[i]] -= 1;
                if (counter[s2[i]] >= 0) {
                    hit += 1;
                }
            }
            
            if (i >= k - 1) {
                if (hit == k) {
                    return true;
                }
            }
        }

        return false;
    }
};