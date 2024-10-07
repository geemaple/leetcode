
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


import heapq

class Solution:
    def decodeString(self, s: str) -> str:
        stack = []

        for x in s:
            if x == ']':
                seg = ''
                while stack[-1] != '[':
                    seg = stack.pop() + seg
                stack.pop()
                count = 0
                power = 1
                while len(stack) > 0 and stack[-1].isdigit():
                    count = int(stack.pop()) * power + count
                    power *= 10
                
                expand = seg * count
                for ch in expand:
                    stack.append(ch)
            else:
                stack.append(x)

        return ''.join(stack)

        

s = Solution()
a = [["a","b","c","e"],["x","x","c","d"],["x","x","b","a"]]
ts = datetime.now()
res = s.decodeString('3[a]2[bc]')
print(datetime.now() - ts)
print(res)
