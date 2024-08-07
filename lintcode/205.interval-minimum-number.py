#  Tag: Segment Tree
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list.
#  Each query has two integers `[start, end]`.
#  For each query, calculate the minimum number between index start and end in the given array,and return  in the result list.
#  
#  **Example 1:**
#  ```
#  Input : array: [1,2,7,8,5], queries :[(1,2),(0,4),(2,4)] .Output: [2,1,5]
#  ```
#  **Example 2:**
#  ```
#  Input : array: [4,5,7,1], queries :[(1,2),(1,3)]. Output: [5,1]
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
class SegmentTreeNode:
    def __init__(self, start: int, end: int, min_val: int):
        self.start = start
        self.end = end
        self.min_val = min_val
        self.left = None
        self.right = None

class SegmentTree:
    def __init__(self, a: list):
        self.root = self.build(a, 0, len(a) - 1)

    def build(self, a: list, start: int, end: int) -> SegmentTreeNode:
        if start > end:
            return None

        node = SegmentTreeNode(start, end, a[start])
        if start == end:
            return node

        mid = (start + end) // 2
        node.left = self.build(a, start, mid)
        node.right = self.build(a, mid + 1, end)
        node.min_val = min(node.left.min_val, node.right.min_val)

        return node

    def query(self, node: SegmentTreeNode, start: int, end: int) -> int:
        if node is None:
            return None

        if start == node.start and end == node.end:
            return node.min_val

        mid = (node.start + node.end) // 2
        if end <= mid:
            return self.query(node.left, start, end)
        elif start > mid:
            return self.query(node.right, start, end)
        else:
            left_val = self.query(node.left, start, mid)
            right_val = self.query(node.right, mid + 1, end)
            return min(left_val, right_val)

class Solution:
    """
    @param a: An integer array
    @param queries: An query list
    @return: The result list
    """
    def interval_min_number(self, a: List[int], queries: List[Interval]) -> List[int]:
        # write your code here
        t = SegmentTree(a)
        res = []
        for q in queries:
            val = t.query(t.root, q.start, q.end)
            res.append(val)
        
        return res