#  Tag: Hash Table, String, Sliding Window
#  Time: O(M + N)
#  Space: O(N)
#  Ref: -
#  Note: -

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

from collections import Counter
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n = len(s)
        k = len(t)
        counter = Counter(t)
        i = 0
        count = 0
        l = -1
        r = -1
        for j in range(n):
            if s[j] in counter: 
                if counter[s[j]] > 0:
                    count += 1
                counter[s[j]] -= 1

            while count == k:
                if l == - 1 or r - l > j - i:
                    l, r = i, j

                if s[i] in counter:
                    counter[s[i]] += 1
                    if counter[s[i]] > 0:
                        count -= 1
                    
                i += 1

        return s[l: r + 1] if l >= 0 else ''