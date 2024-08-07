#  Tag: Segment Tree
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  The structure of Segment Tree is a binary tree which each node has two attributes `start` and `end` denote an segment / interval.
#  
#  _start_ and _end_ are both integers, they should be assigned in following rules:
#  
#  - The root's _start_ and _end_ is given by `build` method.
#  - The left child of node A has `start=A.start, end=(A.start + A.end) / 2`.
#  - The right child of node A has `start=(A.start + A.end) / 2 + 1, end=A.end`.
#  - if _start_ equals to _end_, there will be no children for this node.
#  
#  Implement a `build` method with two parameters _start_ and _end_, so that we can create a corresponding segment tree with every node has the correct _start_ and _end_ value, return the root of this segment tree.
#  
#  **Example 1:**
#  ```
#  Input：[1,4]
#  Output："[1,4][1,2][3,4][1,1][2,2][3,3][4,4]"
#  Explanation：
#  	               [1,  4]
#  	             /        \
#  	      [1,  2]           [3, 4]
#  	      /     \           /     \
#  	   [1, 1]  [2, 2]     [3, 3]  [4, 4]
#  ```
#  **Example 2:**
#  ```
#  Input：[1,6]
#  Output："[1,6][1,3][4,6][1,2][3,3][4,5][6,6][1,1][2,2][4,4][5,5]"
#  Explanation：
#  	       [1,  6]
#               /        \
#        [1,  3]           [4,  6]
#        /     \           /     \
#     [1, 2]  [3,3]     [4, 5]   [6,6]
#     /    \           /     \
#  [1,1]   [2,2]     [4,4]   [5,5]
#  ```
#  
#  Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:
#  
#  - which of these intervals contain a given point
#  - which of these points are in a given interval
#  
#  See wiki:
#  [Segment Tree](https://en.wikipedia.org/wiki/Segment_tree "Segment Tree")
#  [Interval Tree](https://en.wikipedia.org/wiki/Interval_tree "Interval Tree")

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.left, self.right = None, None
"""


class Solution:
    """
    @param: start: start value.
    @param: end: end value.
    @return: The root of Segment Tree.
    """
    def build(self, start, end):
        # write your code here
        if start > end:
            return None

        node = SegmentTreeNode(start, end)
        if start == end:
            return node
        
        mid = (start + end) // 2
        node.left = self.build(start, mid)
        node.right = self.build(mid + 1, end)

        return node