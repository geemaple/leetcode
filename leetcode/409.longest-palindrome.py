#  Tag: Hash Table, String, Greedy
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
#  Letters are case sensitive, for example, "Aa" is not considered a palindrome.
#   
#  Example 1:
#  
#  Input: s = "abccccdd"
#  Output: 7
#  Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
#  
#  Example 2:
#  
#  Input: s = "a"
#  Output: 1
#  Explanation: The longest palindrome that can be built is "a", whose length is 1.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 2000
#  s consists of lowercase and/or uppercase English letters only.
#  
#  

class Solution:
    def longestPalindrome(self, s: str) -> int:
        cache = set()
        res = 0
        for x in s:
            if x in cache:
                res += 2
                cache.remove(x)
            else:
                cache.add(x)

        if len(cache) > 0:
            res += 1

        return res
        