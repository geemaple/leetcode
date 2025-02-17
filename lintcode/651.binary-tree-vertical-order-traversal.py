#  Tag: Hash Table, Breadth First Search/BFS
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-314
#  Note: -

#  Given a binary tree, return the vertical order traversal of its nodes' values.
#  (ie, from top to bottom, column by column).
#  
#  If two nodes are in the same row and column, the order should be from **left to right**.
#  
#  **For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.
#  The root of the tree is at (0, 0).**
#  
#  **Example1**
#  ```
#  Inpurt:  {3,9,20,#,#,15,7}
#  Output: [[9],[3,15],[20],[7]]
#  Explanation:
#     3
#    /\
#   /  \
#   9  20
#      /\
#     /  \
#    15   7
#  ```
#  **Example2**
#  ```
#  Input: {3,9,8,4,0,1,7}
#  Output: [[4],[9],[3,0,1],[8],[7]]
#  Explanation:
#       3
#      /\
#     /  \
#     9   8
#    /\  /\
#   /  \/  \
#   4  01   7
#  ```
#  
#  

from typing import (
    List,
)
from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

from collections import defaultdict, deque
class Solution:
    """
    @param root: the root of tree
    @return: the vertical order traversal
    """
    def vertical_order(self, root: TreeNode) -> List[List[int]]:
        # write your code here
        table = defaultdict(list)
        q = deque([(root, 0)])
        left = sys.maxsize
        right = -sys.maxsize
        while len(q) > 0:
            cur, order = q.popleft()
            if cur is not None:
                left = min(left, order)
                right = max(right, order)

                table[order].append(cur.val)
                q.append((cur.left, order - 1))
                q.append((cur.right, order + 1))

        res = []
        for key in range(left, right + 1):
            res.append(table[key])
            
        return res