//  Tag: Hash Table, String, Sliding Window
//  Time: O(M + N)
//  Space: O(N)
//  Ref: -
//  Note: Hash + TP

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
        unordered_map<char, int> table;
        for (auto c : t) {
            table[c]++;
        }

        int l = 0;
        int count = 0;
        int length = s.size() + 1;
        int head = 0;

        for (int r = 0; r < s.size(); r++) {
            if (table.count(s[r]) > 0) {
                if (table[s[r]] > 0) {
                    count += 1;
                }
                table[s[r]] --;
            }

            while (count == t.size()) {
                if (r - l + 1 < length) {
                    head = l;
                    length = r - l + 1;
                }

                if (table.count(s[l]) > 0) {
                    if (table[s[l]] == 0) {
                        count -= 1;
                    }
                    table[s[l]] ++;
                }

                l++;
            }

        }

        return length > s.size() ? "" : s.substr(head, length); 
    }
};