#  Tag: String
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/fXRjMEGvjJ0

#  A fancy string is a string where no three consecutive characters are equal.
#  Given a string s, delete the minimum possible number of characters from s to make it fancy.
#  Return the final string after the deletion. It can be shown that the answer will always be unique.
#   
#  Example 1:
#  
#  Input: s = "leeetcode"
#  Output: "leetcode"
#  Explanation:
#  Remove an 'e' from the first group of 'e's to create "leetcode".
#  No three consecutive characters are equal, so return "leetcode".
#  
#  Example 2:
#  
#  Input: s = "aaabaaaa"
#  Output: "aabaa"
#  Explanation:
#  Remove an 'a' from the first group of 'a's to create "aabaaaa".
#  Remove two 'a's from the second group of 'a's to create "aabaa".
#  No three consecutive characters are equal, so return "aabaa".
#  
#  Example 3:
#  
#  Input: s = "aab"
#  Output: "aab"
#  Explanation: No three consecutive characters are equal, so return "aab".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists only of lowercase English letters.
#  
#  

class Solution:
    def makeFancyString(self, s: str) -> str:
        n = len(s)
        res = ''
        for i in range(n):
            if i >= 2 and s[i] == s[i - 1] and s[i] == s[i - 2]:
                continue

            res += s[i]

        return res