#  Tag: Hash Table, String, Counting, Enumeration
#  Time: O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given a string s consisting of lowercase English letters.
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
#  Input: s = "zzabccy"
#  Output: 4
#  Explanation:
#  The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​
#  
#  Example 3:
#  
#  Input: s = "aba"
#  Output: 2
#  Explanation:
#  ​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  s consists of lowercase English letters.
#  
#  

class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)

        s = [ord(char) - ord('a') for char in s]

        result = 0
        for l in range(n):
            if n - l <= result:
                break

            cnt = [0] * 26 
            uniq = maxfreq = 0
            for r in range(l, n):
                i = s[r]

                uniq += cnt[i] == 0
                cnt[i] += 1
                if cnt[i] > maxfreq:
                    maxfreq = cnt[i]

                cur = r - l + 1
                if uniq * maxfreq == cur and cur > result:
                    result = cur

        return result