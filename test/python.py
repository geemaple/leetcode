
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        directions = [(1, 1), (0, 1), (1, -1), (0, -1)]

        f = 0
        pos = [0, 0]
        res = 0
        for c in commands:
            if c == -2:
                f = (f + 3) % 4
            elif c == -1:
                f = (f + 1) % 4
            else:
                index = directions[f][0]
                sign = directions[f][1]
                distance = c

                for ob in obstacles:
                    if pos[1 - index] == ob[1 - index]:
                        if sign > 0 and ob[index] > pos[index]:
                            distance = min(c, ob[index] - pos[index] - 1)
                        elif sign < 0 and ob[index] < pos[index]:
                            distance = min(c, pos[index] - ob[index] - 1)

                pos[index] += sign * distance
                res = max(res, pos[0] ** 2 + pos[1] ** 2)
        return res

s = Solution()
res = s.robotSim([7,-2,-2,7,5], [[-3,2],[-2,1],[0,1],[-2,4],[-1,0],[-2,-3],[0,-3],[4,4],[-3,3],[2,2]])
print(res)