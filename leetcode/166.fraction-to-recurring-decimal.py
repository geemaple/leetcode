#  Tag: Hash Table, Math, String
#  Time: O(D)
#  Space: O(D)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/W2StRNk9S7E

#  Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
#  If the fractional part is repeating, enclose the repeating part in parentheses.
#  If multiple answers are possible, return any of them.
#  It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
#   
#  Example 1:
#  
#  Input: numerator = 1, denominator = 2
#  Output: "0.5"
#  
#  Example 2:
#  
#  Input: numerator = 2, denominator = 1
#  Output: "2"
#  
#  Example 3:
#  
#  Input: numerator = 4, denominator = 333
#  Output: "0.(012)"
#  
#   
#  Constraints:
#  
#  -231 <= numerator, denominator <= 231 - 1
#  denominator != 0
#  
#  

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return '0'

        res = ''
        if (numerator < 0) ^ (denominator < 0):
            res += '-'

        numerator = abs(numerator)
        denominator = abs(denominator)

        res += str(numerator // denominator)
        numerator %= denominator
        if numerator == 0:
            return res

        res += '.'
        cache = {}
        cache[numerator] = len(res)
        while numerator != 0:
            numerator *= 10
            res += str(numerator // denominator)
            numerator %= denominator
            if numerator in cache:
                l = cache[numerator]
                res = res[:l] + '(' + res[l:] + ')'
                break
            else:
                cache[numerator] = len(res)

        return res