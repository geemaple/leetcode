#  Tag: Math
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer num, return a string of its base 7 representation.
#   
#  Example 1:
#  Input: num = 100
#  Output: "202"
#  Example 2:
#  Input: num = -7
#  Output: "-10"
#  
#   
#  Constraints:
#  
#  -107 <= num <= 107
#  
#  

class Solution:
    def convertToBase7(self, num: int) -> str:

        if num == 0:
            return "0"

        res = ""
        sign = "" if num > 0 else "-"
        num = abs(num)
        while num > 0:
            d = num % 7
            num = num // 7

            res = str(d) + res

        return sign + res