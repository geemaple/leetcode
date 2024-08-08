from typing import List
import heapq
class Solution:
    def calculate(self, s: str) -> int:
        n = len(s)
        i = 0
        j = 0
        numbers = []
        ops = []
        for j in range(n):


            
            if s[j] in ['+', '-', '*', '/']:
                ops.append(s[j])
                numbers.append(int(s[i:j].strip()))
                i = j + 1

            if len(numbers) - len(ops) == 1 and ops[-1] in ['*', '/']:
                r = numbers.pop()
                l = numbers.pop()
                op = ops.pop()
                if op == '*':
                    numbers.append(l * r)
                else:
                    numbers.append(l // r)

            
        
        numbers.append(int(s[i:].strip()))
        

        return 0     
        


s = Solution()
res = s.calculate("3+2*2")
print(res)