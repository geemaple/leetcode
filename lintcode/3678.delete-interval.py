#  Tag: Sweep Line
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-1272
#  Note: -

#  The set of real numbers can be represented as a concatenation of a number of disjoint intervals, each of which is of the form `[a, b)`, denoting the set of all real numbers `x` that satisfy $a \le x < b$.
#  A real number `x` is said to be in the set if some interval `[a, b)` contains the real number `x`.
#  
#  Now you are given a **sorted** list of disjoint `intervals`, which represents a set of real numbers, where each item `intervals[i] = [ai, bi]` represents an interval $[a_i, b_i)$.
#  Then you are given an interval `toBeRemoved` to remove.
#  
#  You need to return **a set of real numbers** that represent the portions of `intervals` that have **deleted** `toBeRemoved`.
#  In other words, return the set of real numbers and satisfy that every real number `x` in the set is in `intervals` but not in `toBeRemoved`.
#  Your answer should be an **ordered** list of disjoint intervals as described above.
#  
#  **Example 1**
#  
#  Input
#  ```
#  intervals = [[0,2],[3,4],[5,7]]
#  toBeRemoved = [1,6]
#  ```
#  Output
#  ```
#  [[0,1],[6,7]]
#  ```
#  
#  **Example 2**
#  
#  Input
#  ```
#  intervals = [[0,5]]
#  toBeRemoved = [2,3]
#  ```
#  
#  Output
#  ```
#  [[0,2],[3,5]]
#  ```
#  
#  **Example 3**
#  
#  Input
#  ```
#  intervals = [[-5,-4],[-3,-2],[1,2],[3,5],[8,9]]
#  toBeRemoved = [-1,4]
#  ```
#  
#  Output
#  ```
#  [[-5,-4],[-3,-2],[4,5],[8,9]]
#  ```
#  
#  $1 \le intervals.length \le 104$
#  
#  $-10^9 \le a_i < b_i \le 10^9$

from typing import (
    List,
)

class Solution:
    """
    @param intervals: A sorted list of disjoint intervals.
    @param to_be_removed: An interval to be removed.
    @return: A set of real numbers.
    """
    def delete_interval(self, intervals: List[List[int]], to_be_removed: List[int]) -> List[List[int]]:
        # --- write your code here ---
        res = []
        for l, r in intervals:
            if to_be_removed[1] < l or to_be_removed[0] > r:
                res.append([l, r])
            else:
                if l < to_be_removed[0]:
                    res.append([l, to_be_removed[0]])
                if r > to_be_removed[1]:
                    res.append([to_be_removed[1], r])

        return res

from collections import defaultdict
class Solution:
    """
    @param intervals: A sorted list of disjoint intervals.
    @param to_be_removed: An interval to be removed.
    @return: A set of real numbers.
    """
    def delete_interval(self, intervals: List[List[int]], to_be_removed: List[int]) -> List[List[int]]:
        # --- write your code here ---
        lines = defaultdict(int)
        for s, e in intervals:
            lines[s] += 1
            lines[e] -= 1

        lines[to_be_removed[0]] -= 1
        lines[to_be_removed[1]] += 1

        prefix = 0
        added = False
        res = []
        for num in sorted(lines.keys()):
            prefix += lines[num]
            if prefix == 1:
                res.append([num, num])
                added = True
            
            if prefix == 0 and added:
                res[-1][1] = num
                added = False
        return res