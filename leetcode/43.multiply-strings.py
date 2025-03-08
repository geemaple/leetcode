#  Tag: Math, String, Simulation
#  Time: O(NM)
#  Space: O(N+M)
#  Ref: -
#  Note: -

#  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
#  Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
#   
#  Example 1:
#  Input: num1 = "2", num2 = "3"
#  Output: "6"
#  Example 2:
#  Input: num1 = "123", num2 = "456"
#  Output: "56088"
#  
#   
#  Constraints:
#  
#  1 <= num1.length, num2.length <= 200
#  num1 and num2 consist of digits only.
#  Both num1 and num2 do not contain any leading zero, except the number 0 itself.
#  
#  

class Solution:
    def multiply(self, num1: str, num2: str) -> str:

        if (num1 == '0' or num2 == '0'):
            return '0'

        n = len(num1)
        m = len(num2)
        digits = [0 for i in range(n + m)]
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                digits[i + j + 1] += int(num1[i]) * int(num2[j])
                digits[i + j] += digits[i + j + 1] // 10
                digits[i + j + 1] %= 10
        
        res = ''
        for i in range(m + n):
            if digits[i] == 0 and len(res) == 0:
                continue

            res += str(digits[i])
        return res