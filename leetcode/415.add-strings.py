#  Tag: Math, String, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
#  You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.
#   
#  Example 1:
#  
#  Input: num1 = "11", num2 = "123"
#  Output: "134"
#  
#  Example 2:
#  
#  Input: num1 = "456", num2 = "77"
#  Output: "533"
#  
#  Example 3:
#  
#  Input: num1 = "0", num2 = "0"
#  Output: "0"
#  
#   
#  Constraints:
#  
#  1 <= num1.length, num2.length <= 104
#  num1 and num2 consist of only digits.
#  num1 and num2 don't have any leading zeros except for the zero itself.
#  
#  

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i = len(num1) - 1
        j = len(num2) - 1
        addition = 0
        
        res = ''
        while i >= 0 or j >= 0 or addition > 0:
            l = num1[i] if i >= 0 else 0
            r = num2[j] if j >= 0 else 0

            digit = int(l) + int(r) + addition
            addition = digit // 10
            digit = digit % 10
            res = str(digit) + res

            i -= 1
            j -= 1
        
        return res