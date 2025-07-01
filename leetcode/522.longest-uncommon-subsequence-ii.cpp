//  Tag: Array, Hash Table, Two Pointers, String, Sorting
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
//  An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
//  A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
//  
//  For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
//  
//   
//  Example 1:
//  Input: strs = ["aba","cdc","eae"]
//  Output: 3
//  Example 2:
//  Input: strs = ["aaa","aaa","aa"]
//  Output: -1
//  
//   
//  Constraints:
//  
//  2 <= strs.length <= 50
//  1 <= strs[i].length <= 10
//  strs[i] consists of lowercase English letters.
//  
//  

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(), [](auto &a, auto &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> counter;
        for (auto &s: strs) {
            counter[s] += 1;
        }

        for (int i = n - 1; i >= 0; i--) {
            if (counter[strs[i]] == 1) {
                bool unique = true;
                for (int j = i + 1; j < n; j++) {
                    if (j + 1 < n && strs[j] == strs[j + 1]) {
                        continue;
                    }

                    if (check(strs[j], strs[i])) {
                        unique = false;
                        break;
                    }
                }

                if (unique) {
                    return strs[i].size();
                }
            }
        }

        return -1;
    }

    bool check(string &s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s1[i] == s2[j]) {
                j += 1;
            }
        }
        return j == m;
    }
};