#  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.
#  As a reminder, a binary search tree is a tree that satisfies these constraints:
#  
#  The left subtree of a node contains only nodes with keys less than the node's key.
#  The right subtree of a node contains only nodes with keys greater than the node's key.
#  Both the left and right subtrees must also be binary search trees.
#  
#   
#  Example 1:
#  
#  
#  Input: root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
#  Output: [30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
#  
#  Example 2:
#  
#  Input: root = [0,null,1]
#  Output: [1,null,1]
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 104].
#  -104 <= Node.val <= 104
#  All the values in the tree are unique.
#  root is guaranteed to be a valid binary search tree.
#  
#   
#  Note: This question is the same as 1038: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.helper(root, 0)
        return root

    def helper(self, node:TreeNode, pre: int) -> int:
        if node is None:
            return pre

        pre = self.helper(node.right, pre)
        node.val += pre
        pre = node.val

        return self.helper(node.left, pre)
    

class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.pre = 0
        self.helper(root)
        return root

    def helper(self, node:TreeNode):
        if node is None:
            return

        self.helper(node.right)
        node.val += self.pre
        self.pre = node.val

        self.helper(node.left)