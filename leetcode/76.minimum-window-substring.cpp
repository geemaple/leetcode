//  Tag: Hash Table, String, Sliding Window
//  Time: O(M + N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
//  The testcases will be generated such that the answer is unique.
//   
//  Example 1:
//  
//  Input: s = "ADOBECODEBANC", t = "ABC"
//  Output: "BANC"
//  Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
//  
//  Example 2:
//  
//  Input: s = "a", t = "a"
//  Output: "a"
//  Explanation: The entire string s is the minimum window.
//  
//  Example 3:
//  
//  Input: s = "a", t = "aa"
//  Output: ""
//  Explanation: Both 'a's from t must be included in the window.
//  Since the largest window of s only has one 'a', return empty string.
//  
//   
//  Constraints:
//  
//  m == s.length
//  n == t.length
//  1 <= m, n <= 105
//  s and t consist of uppercase and lowercase English letters.
//  
//   
//  Follow up: Could you find an algorithm that runs in O(m + n) time?
//  

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int k = t.size();
        unordered_map<char, int> counter;
        for (auto c : t) {
            counter[c]++;
        }

        int i = 0;
        int count = 0;
        int l = -1;
        int r = -1;

        for (int j = 0; j < n; j++) {
            if (counter.count(s[j]) > 0) {
                if (counter[s[j]] > 0) {
                    count += 1;
                }
                counter[s[j]] -= 1;
            }

            while (count == k) {
                if (l == -1 || j - i < r - l) {
                    l = i;
                    r = j;
                }

                if (counter.count(s[i]) > 0) {
                    counter[s[i]] += 1;
                    if (counter[s[i]] > 0) {
                        count -= 1;
                    }
                }
                
                i += 1;
            }
        }
        return l >= 0 ? s.substr(l, r - l + 1): "";
    }
};