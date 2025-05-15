#  Tag: Hash Table, Math, String, Dynamic Programming, Counting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/QGsDIA8qaOE

#  You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:
#  
#  If the character is 'z', replace it with the string "ab".
#  Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
#  
#  Return the length of the resulting string after exactly t transformations.
#  Since the answer may be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: s = "abcyy", t = 2
#  Output: 7
#  Explanation:
#  
#  First Transformation (t = 1):
#  
#  	
#  'a' becomes 'b'
#  'b' becomes 'c'
#  'c' becomes 'd'
#  'y' becomes 'z'
#  'y' becomes 'z'
#  String after the first transformation: "bcdzz"
#  
#  
#  Second Transformation (t = 2):
#  	
#  'b' becomes 'c'
#  'c' becomes 'd'
#  'd' becomes 'e'
#  'z' becomes "ab"
#  'z' becomes "ab"
#  String after the second transformation: "cdeabab"
#  
#  
#  Final Length of the string: The string is "cdeabab", which has 7 characters.
#  
#  
#  Example 2:
#  
#  Input: s = "azbk", t = 1
#  Output: 5
#  Explanation:
#  
#  First Transformation (t = 1):
#  
#  	
#  'a' becomes 'b'
#  'z' becomes "ab"
#  'b' becomes 'c'
#  'k' becomes 'l'
#  String after the first transformation: "babcl"
#  
#  
#  Final Length of the string: The string is "babcl", which has 5 characters.
#  
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists only of lowercase English letters.
#  1 <= t <= 105
#  
#  

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = 10 ** 9 + 7
        counter = [0 for i in range(26)]
        for x in s:
            counter[ord(x) - ord('a')] += 1

        for i in range(t):
            z = counter[25]
            counter = [0] + counter[:-1]
            counter[0] = z
            counter[1] = (z + counter[1]) % mod

        return sum(counter) % mod

class Solution:
    def lengthAfterTransformations(self, s: str, t: int) -> int:
        mod = 10 ** 9 + 7
        dp = [0 for i in range(t + 26)]
        for i in range(26):
            dp[i] = 1

        for i in range(26, t + 26):
            dp[i] = dp[i - 26] + dp[i - 26 + 1] % mod

        res = 0
        for i in range(len(s)):
            res = (res + dp[ord(s[i]) - ord('a') + t]) % mod

        return res