#  Tag: String, Stack, Greedy
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/wwjT-h94lUE

#  You are given a string s and two integers x and y. You can perform two types of operations any number of times.
#  
#  Remove substring "ab" and gain x points.
#  
#  	
#  For example, when removing "ab" from "cabxbae" it becomes "cxbae".
#  
#  
#  Remove substring "ba" and gain y points.
#  	
#  For example, when removing "ba" from "cabxbae" it becomes "cabxe".
#  
#  
#  
#  Return the maximum points you can gain after applying the above operations on s.
#   
#  Example 1:
#  
#  Input: s = "cdbcbbaaabab", x = 4, y = 5
#  Output: 19
#  Explanation:
#  - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
#  - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
#  - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
#  - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
#  Total score = 5 + 4 + 5 + 5 = 19.
#  Example 2:
#  
#  Input: s = "aabbaaxybbaabb", x = 5, y = 4
#  Output: 20
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  1 <= x, y <= 104
#  s consists of lowercase English letters.
#  
#  

class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a = 'ab'
        b = 'ba'  
        if x < y:
            x, y = y, x
            a, b = b, a

        s, score1 = self.score(s, a, x)
        s, score2 = self.score(s, b, y)      

        return score1 + score2


    def score(self, s: str, t: str, p: int) -> (str, int):
        res = ''
        score = 0
        for x in s:
            res += x
            if res[-2:] == t:
                score += p
                res = res[0: -2]

        return res, score