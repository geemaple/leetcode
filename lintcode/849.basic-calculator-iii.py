#  Tag: Stack, String, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-772
#  Note: -

#  Implement a basic calculator to evaluate a simple expression string.
#  
#  
#  The expression string contains only non-negative integers, `+`, `-`, `*`, `/` operators , open `(` and closing parentheses `)` and empty spaces .
#  The integer division should truncate toward zero.
#  
#  You may assume that **the given expression is always valid**.
#  All intermediate results will be in the range of `[-2147483648, 2147483647]`
#  
#  **Example 1:**
#  ```
#  Input："1 + 1"
#  Output：2
#  Explanation：1 + 1 = 2
#  ```
#  
#  
#  **Example 2:**
#  ```
#  Input：" 6-4 / 2 "
#  Output：4
#  Explanation：4/2=2，6-2=4
#  ```
#  
#  Do not use the `eval` built-in library function.

import math
class Solution:
    """
    @param s: the expression string
    @return: the answer
    """
    def calculate(self, s: str) -> int:
        return self.helper(s, 0)[0]

    def helper(self, s: str, i: int) -> int:
        left = 0  # stack except top
        right = 0 # stack top
        num = 0
        op = '+'
        while i < len(s):
            char = s[i]
            if char.isdigit():
                num = num * 10 + int(char)

            if (not char.isdigit() and char != ' ') or i == len(s) - 1:  
                if char == '(':
                    num, i = self.helper(s, i + 1)

                if op == '+':
                    left += right
                    right = num
                elif op == '-':
                    left += right
                    right = -num
                elif op == '*':
                    right *= num
                elif op == '/':
                    right = math.trunc(right / num)

                op = char
                num = 0
        
                if char == ')':
                    break
            i += 1
            
        return left + right, i