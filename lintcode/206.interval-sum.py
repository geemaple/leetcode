#  Tag: Segment Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list.
#  Each query has two integers `[start, end]`.
#  For each query, calculate the sum of numbers between index start and end in the given array and return in the result list.
#  
#  **Example 1:**
#  ```
#  Input: array = [1,2,7,8,5],  queries = [(0,4),(1,2),(2,4)]
#  Output: [23,9,20]
#  ```
#  
#  **Example 2:**
#  ```
#  Input: array = [4,3,1,2],  queries = [(1,2),(0,2)]
#  Output: [4,8]
#  ```
#  
#  We suggest you finish problem [Segment Tree Build](https://www.lintcode.com/problem/segment-tree-build/ ), [Segment Tree Query](https://www.lintcode.com/problem/segment-tree-query/) and [Segment Tree Modify](https://www.lintcode.com/problem/segment-tree-modify/) first.

from typing import (
    List,
)
from lintcode import (
    Interval,
)

"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param a: An integer list
    @param queries: An query list
    @return: The result list
    """
    def interval_sum(self, a: List[int], queries: List[Interval]) -> List[int]:
        # write your code here
        prefix_sum = [0]
        for x in a:
            prefix_sum.append(prefix_sum[-1] + x)
        
        res = []
        for interval in queries:
            res.append(prefix_sum[interval.end + 1] - prefix_sum[interval.start])
        
        return res
    
# Follow up
class SegmentTreeNode:
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.left, self.right = None, None
        self.sum = 0

class Solution:
    """
    @param a: An integer list
    @param queries: An query list
    @return: The result list
    """
    def interval_sum(self, a: List[int], queries: List[Interval]) -> List[int]:
        # write your code here
        root = self.build(0, len(a) - 1, a)
        res = []
        for q in queries:
            sum = self.query(root, q.start, q.end)
            res.append(sum)

        return res

    def query(self, root: SegmentTreeNode, start: int, end: int) -> int:
        if root is None:
            return 0

        if root.start == start and root.end == end:
            return root.sum

        mid = root.start + (root.end - root.start) // 2
 
        if end <= mid:
            return self.query(root.left, start, end)
        elif start > mid:
            return self.query(root.right, start, end)
        else:
            left = self.query(root.left, start, mid)
            right = self.query(root.right, mid + 1, end)
            return left + right

    def build(self, start: int, end: int, vals: list) -> SegmentTreeNode:
        if start > end:
            return None

        node = SegmentTreeNode(start, end)
        if start == end:
            node.sum = vals[start]
            return node

        mid = start + (end - start) // 2
        node.left = self.build(start, mid, vals)
        node.right = self.build(mid + 1, end, vals)

        node.sum = node.left.sum + node.right.sum
        return node