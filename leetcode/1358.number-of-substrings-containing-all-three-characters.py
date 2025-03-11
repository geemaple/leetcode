#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/z1NZNOeQXGw

#  Given a string s consisting only of characters a, b and c.
#  Return the number of substrings containing at least one occurrence of all these characters a, b and c.
#   
#  Example 1:
#  
#  Input: s = "abcabc"
#  Output: 10
#  Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
#  
#  Example 2:
#  
#  Input: s = "aaacb"
#  Output: 3
#  Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
#  
#  Example 3:
#  
#  Input: s = "abc"
#  Output: 1
#  
#   
#  Constraints:
#  
#  3 <= s.length <= 5 x 10^4
#  s only consists of a, b or c characters.
#  
#  

from collections import defaultdict
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        i = 0
        counter = defaultdict(int)
        for j in range(n):
            counter[s[j]] += 1

            while len(counter) == 3:
                res += n - j
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]

                i += 1

        return res