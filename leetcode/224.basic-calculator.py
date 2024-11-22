#  Tag: Math, String, Stack, Recursion
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
#  Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
#   
#  Example 1:
#  
#  Input: s = "1 + 1"
#  Output: 2
#  
#  Example 2:
#  
#  Input: s = " 2-1 + 2 "
#  Output: 3
#  
#  Example 3:
#  
#  Input: s = "(1+(4+5+2)-3)+(6+8)"
#  Output: 23
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 3 * 105
#  s consists of digits, '+', '-', '(', ')', and ' '.
#  s represents a valid expression.
#  '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
#  '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
#  There will be no two consecutive operators in the input.
#  Every number and running calculation will fit in a signed 32-bit integer.
#  
#  

class Solution:
    def calculate(self, s: str) -> int:
        stack = []
        num = 0
        sign = 1
        result = 0

        for char in s:
            if char.isdigit():
                num = num * 10 + int(char)
            elif char in "+-":
                result += sign * num
                num = 0
                sign = 1 if char == '+' else -1
            elif char == "(":
                stack.append(result)
                stack.append(sign)
                result = 0
                sign = 1
            elif char == ")":
                result += sign * num
                num = 0
                result *= stack.pop()
                result += stack.pop()

        return result + sign * num

class Solution:
    def calculate(self, s: str) -> int:
        res, i = self.cal(s + '+', 0)
        return res

    def cal(self, s: str, i: int) -> int:
        n = len(s)
        pre, cur = 0, 0
        op = None
        
        while i < n:
            while s[i] == ' ':
                i += 1

            num = 0
            sign = 1
            if s[i] == '-':
                sign = -1
                i += 1
                
            while s[i].isdigit():
                num = num * 10 + int(s[i])
                i += 1

            while s[i] == ' ':
                i += 1

            if s[i] == '(':
                num, i = self.cal(s, i + 1)

            num = num * sign
            if op is None:
                cur = num
            elif op == '+':
                pre = pre + cur
                cur = num
            elif op == '-':
                pre = pre + cur
                cur = -num

            if s[i] == ')':
                return pre + cur, i + 1

            op = s[i]
            i += 1
            
        return pre + cur, i
            







