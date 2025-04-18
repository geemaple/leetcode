#  Tag: Prefix Sum Array, Array, Line Sweep
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-2237
#  Note: -

#  A street has a number of streetlights whose coordinates are given by an array of `lights`, each `lights[i] = [position, range]` denoting the streetlight whose coordinates are at `position` and which can illuminate the range `[position - range, position + range]` including the boundary points.
#  
#  When a position `p`, exists that is illuminated by more than one streetlight, this position is a little brighter, now given `lights`, return the **brightest horizontal coordinate position**, and **if more than one position with the same brightness exists, return the one with the smallest coordinates.**
#  
#  Example 1:
#  ```
#  Input:
#  lights = [[-3, 2], [1, 2], [3, 2]]
#  Output:
#  -1
#  Explanation:
#  The first streetlight illuminates the range [-5, -1]
#  The second streetlight illuminates the range [-1, 3]
#  The third streetlight illuminates the range [1, 5]
#  Positions -1, 1, 2, 3 are all illuminated by two streetlights
#  So we return the smallest coordinate, -1
#  ```
#  
#  ![3745.png](https://media-cn.lintcode.com/new_storage_v2/public/202310/a0f462329571446d9c8e00cf8df2014b/3745.png)
#  
#  Example 2:
#  ```
#  Input:
#  lights = [[1, 0], [0, 1]]
#  Output:
#  1
#  ```
#  
#  $1 \leq lights.length \leq 10^5$
#  $lights[i].length == 2$
#  $-10^8 \leq position \leq 10^8$
#  $0 \leq range \leq 10^8$

from typing import (
    List,
)
from collections import defaultdict
class Solution:
    """
    @param lights: Location and extent of illumination of street lights
    @return: The brightest position
    """
    def brightest_position(self, lights: List[List[int]]) -> int:
        # write your code here
        lines = defaultdict(int)
        for p, r in lights:
            lines[p - r] += 1
            lines[p + r + 1] -= 1

        print(lines)
        prefix = 0
        brightest = 0
        res = 0
        for pos in sorted(lines.keys()):
            prefix += lines[pos]
            if prefix > brightest:
                brightest = prefix
                res = pos
        return res