from typing import List
import heapq
class Solution:
    def calculate(self, s: str) -> int:
        s = '+' +  s + '+'
        n = len(s)
        stack = []
        num = 0
        op = None
        for i in range(n):
            if s[i] == ' ':
                continue

            if s[i].isdigit():
                num = num * 10 + int(s[i])
            else:
                if op == '+':
                    stack.append(num)
                elif op == '-':
                    stack.append(-num)
                elif op == '*':
                    res = stack.pop() * num
                    stack.append(res)
                elif op == '/':
                    left = stack.pop()
                    sign = left // abs(left)
                    res = abs(left) // num
                    stack.append(sign * res)
                
                num = 0
                op = s[i]

        return sum(stack)
        


s = Solution()
res = s.calculate("14 - 3 / 2")
print(res)