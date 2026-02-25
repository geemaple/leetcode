#  Tag: Hash Table, String, Prefix Sum
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  You are given a string s consisting only of the characters 'a', 'b', and 'c'.
#  A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
#  Return the length of the longest balanced substring of s.
#   
#  Example 1:
#  
#  Input: s = "abbac"
#  Output: 4
#  Explanation:
#  The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
#  
#  Example 2:
#  
#  Input: s = "aabcc"
#  Output: 3
#  Explanation:
#  The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.
#  
#  Example 3:
#  
#  Input: s = "aba"
#  Output: 2
#  Explanation:
#  One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s contains only the characters 'a', 'b', and 'c'.
#  
#  

class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 1  # at least one character is always balanced

        # -----------------------------
        # Case 1: single character runs
        # -----------------------------
        i = 0
        while i < n:
            j = i
            while j < n and s[j] == s[i]:
                j += 1
            ans = max(ans, j - i)
            i = j

        # -----------------------------
        # Case 2: exactly 2 characters
        # -----------------------------
        def longest_two(c1, c2):
            diff = 0
            first = {0: -1}
            best = 0

            for i, ch in enumerate(s):
                if ch == c1:
                    diff += 1
                elif ch == c2:
                    diff -= 1
                else:
                    # third character breaks the substring
                    diff = 0
                    first = {0: i}
                    continue

                if diff in first:
                    best = max(best, i - first[diff])
                else:
                    first[diff] = i
            return best

        ans = max(ans,
                  longest_two('a', 'b'),
                  longest_two('a', 'c'),
                  longest_two('b', 'c'))

        # -----------------------------
        # Case 3: all 3 characters
        # -----------------------------
        cntA = cntB = cntC = 0
        mp = {(0, 0): -1}
        best = 0

        for i, ch in enumerate(s):
            if ch == 'a':
                cntA += 1
            elif ch == 'b':
                cntB += 1
            else:
                cntC += 1

            key = (cntA - cntB, cntA - cntC)
            if key in mp:
                best = max(best, i - mp[key])
            else:
                mp[key] = i

        return max(ans, best)