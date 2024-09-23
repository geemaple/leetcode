#  Tag: Hash Table, String, Sliding Window
#  Time: O(M + N)
#  Space: O(N)
#  Ref: -
#  Note: Hash + TP

#  Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
#  The testcases will be generated such that the answer is unique.
#   
#  Example 1:
#  
#  Input: s = "ADOBECODEBANC", t = "ABC"
#  Output: "BANC"
#  Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
#  
#  Example 2:
#  
#  Input: s = "a", t = "a"
#  Output: "a"
#  Explanation: The entire string s is the minimum window.
#  
#  Example 3:
#  
#  Input: s = "a", t = "aa"
#  Output: ""
#  Explanation: Both 'a's from t must be included in the window.
#  Since the largest window of s only has one 'a', return empty string.
#  
#   
#  Constraints:
#  
#  m == s.length
#  n == t.length
#  1 <= m, n <= 105
#  s and t consist of uppercase and lowercase English letters.
#  
#   
#  Follow up: Could you find an algorithm that runs in O(m + n) time?
#  

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        table = {}
        for c in t:
            table[c] = table.get(c, 0) + 1

        counter = 0
        l = 0
        head = 0
        length = len(s) + 1

        for r in range(len(s)):
            if s[r] in table:
                if table[s[r]] > 0:
                    counter += 1
                table[s[r]] -= 1

            while counter == len(t):
                if r - l + 1 < length:
                    head = l
                    length = r - l + 1

                if s[l] in table:
                    if table[s[l]] == 0:
                        counter -= 1
                    table[s[l]] += 1

                l += 1

        return "" if length > len(s) else s[head: head + length]