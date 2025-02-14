#  Tag: String, Sliding Window
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
#  Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
#   
#  Example 1:
#  
#  Input: s = "abciiidef", k = 3
#  Output: 3
#  Explanation: The substring "iii" contains 3 vowel letters.
#  
#  Example 2:
#  
#  Input: s = "aeiou", k = 2
#  Output: 2
#  Explanation: Any substring of length 2 contains 2 vowels.
#  
#  Example 3:
#  
#  Input: s = "leetcode", k = 3
#  Output: 2
#  Explanation: "lee", "eet" and "ode" contain 2 vowels.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists of lowercase English letters.
#  1 <= k <= s.length
#  
#  

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        n = len(s)
        count = 0
        res = 0
        vowels = {'a','e','i','o','u'}
        for i in range(n):
            if s[i] in vowels:
                count += 1

            if i >= k - 1:
                res = max(res, count)
                if s[i - k + 1] in vowels:
                    count -= 1
        return res