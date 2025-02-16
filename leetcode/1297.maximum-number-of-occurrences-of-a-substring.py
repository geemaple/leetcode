#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Given a string s, return the maximum number of occurrences of any substring under the following rules:
#  
#  The number of unique characters in the substring must be less than or equal to maxLetters.
#  The substring size must be between minSize and maxSize inclusive.
#  
#   
#  Example 1:
#  
#  Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
#  Output: 2
#  Explanation: Substring "aab" has 2 occurrences in the original string.
#  It satisfies the conditions, 2 unique letters and size 3 (between minSize and maxSize).
#  
#  Example 2:
#  
#  Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
#  Output: 2
#  Explanation: Substring "aaa" occur 2 times in the string. It can overlap.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  1 <= maxLetters <= 26
#  1 <= minSize <= maxSize <= min(26, s.length)
#  s consists of only lowercase English letters.
#  
#  

from collections import defaultdict
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n = len(s)
        counter = defaultdict(int)
        i = 0
        res = 0
        res_count = defaultdict(int)
        for j in range(n):
            counter[s[j]] += 1
 
            while (j - i + 1 >= minSize):
                if j - i + 1 <= maxSize and len(counter) <= maxLetters:
                    sub = s[i: j + 1]
                    res_count[sub] += 1
                    res = max(res, res_count[sub])
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]
                i += 1

        return res