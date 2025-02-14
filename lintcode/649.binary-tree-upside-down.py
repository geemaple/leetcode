#  Tag: Binary Tree, Depth First Search/DFS, Divide and Conquer
#  Time: O(N)
#  Space: O(H)
#  Ref: Leetcode-156
#  Note: -

#  Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes.
#  Return the new root.
#  
#  **Example1**
#  
#  ```plain
#  Input: {1,2,3,4,5}
#  Output: {4,5,2,#,#,3,1}
#  Explanation:
#  The input is
#      1
#     / \
#    2   3
#   / \
#  4   5
#  and the output is
#     4
#    / \
#   5   2
#      / \
#     3   1
#  ```
#  
#  **Example2**
#  
#  ```plain
#  Input: {1,2,3,4}
#  Output: {4,#,2,3,1}
#  Explanation:
#  The input is
#      1
#     / \
#    2   3
#   /
#  4
#  and the output is
#     4
#      \
#       2
#      / \
#     3   1
#  ```
#  
#  

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

class Solution:
    """
    @param root: the root of binary tree
    @return: new root
    """
    def upside_down_binary_tree(self, root: TreeNode) -> TreeNode:
        # write your code here
        if root is None or root.left is None:
            return root

        new_root = self.upside_down_binary_tree(root.left)
        root.left.left = root.right
        root.left.right = root
        root.right = None
        root.left = None
        return new_root

class Solution:
    """
    @param root: the root of binary tree
    @return: new root
    """
    def upside_down_binary_tree(self, root: TreeNode) -> TreeNode:
        # write your code here
        stack = []
        cur = root
        while cur is not None:
            stack.append(cur)
            cur = cur.left

        dummy = TreeNode(0)
        pre = dummy
        while len(stack) > 0:
            cur = stack.pop()
            pre.right = cur
            pre.left = cur.right
            pre = cur
            cur.left = None
            cur.right = None

        return dummy.right
    
class Solution:
    """
    @param root: the root of binary tree
    @return: new root
    """
    def upside_down_binary_tree(self, root: TreeNode) -> TreeNode:
        # write your code here
        pre = None
        cur = root
        rchild = None

        # Similar to reversing a singly linked list with special right child handling
        while cur:
            tmp = cur.left
            
            cur.left = rchild
            rchild = cur.right
            
            cur.right = pre
            
            pre = cur
            cur = tmp
        
        return pre