#  Tag: Binary Tree, Binary Search Tree
#  Time: O(H)
#  Space: O(1)
#  Ref: Leetcode-285
#  Note: Successor

#  Given a binary search tree ([See Definition](http://www.lintcode.com/problem/validate-binary-search-tree/ "BST")) and a node in it, find the in-order successor of that node in the BST.
#  
#  If the given node has no in-order successor in the tree, return `null`.
#  
#  **Example 1:**
#  
#  ```
#  Input: {1,#,2}, node with value 1
#  Output: 2
#  Explanation:
#    1
#     \
#      2
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: {2,1,3}, node with value 1
#  Output: 2
#  Explanation: 
#      2
#     / \
#    1   3
#  ```
#  
#  [Binary Tree Representation](https://www.lintcode.com/help/binary-tree-representation/)
#  
#  It's guaranteed *p* is one node in the given tree. (You can directly compare the memory address to find p)

"""
Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""


class Solution:
    """
    @param: root: The root of the BST.
    @param: p: You need find the successor node of p.
    @return: Successor of p.
    """
    def inorderSuccessor(self, root, p):
        # write your code here
        node = root
        successor = None
        while (node):
            if p.val < node.val:
                successor = node
                node = node.left
            else:
                node = node.right

        return successor

class Solution:
    """
    @param: root: The root of the BST.
    @param: p: You need find the successor node of p.
    @return: Successor of p.
    """
    def inorderSuccessor(self, root, p):
        # write your code here
        stack = []
        cur = root
        find = False
        while len(stack) > 0 or cur is not None:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            if find:
                return cur

            if cur == p:
                find = True

            cur = cur.right

        return None
