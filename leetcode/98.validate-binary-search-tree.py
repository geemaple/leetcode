#
# @lc app=leetcode id=98 lang=python
#
# [98] Validate Binary Search Tree
#
# https://leetcode.com/problems/validate-binary-search-tree/description/
#
# algorithms
# Medium (27.32%)
# Total Accepted:    648.7K
# Total Submissions: 2.4M
# Testcase Example:  '[2,1,3]'
#
# Given a binary tree, determine if it is a valid binary search tree (BST).
# 
# Assume a BST is defined as follows:
# 
# 
# The left subtree of a node contains only nodes with keys less than the node's
# key.
# The right subtree of a node contains only nodes with keys greater than the
# node's key.
# Both the left and right subtrees must also be binary search trees.
# 
# 
# 
# 
# Example 1:
# 
# 
# ⁠   2
# ⁠  / \
# ⁠ 1   3
# 
# Input: [2,1,3]
# Output: true
# 
# 
# Example 2:
# 
# 
# ⁠   5
# ⁠  / \
# ⁠ 1   4
# / \
# 3   6
# 
# Input: [5,1,4,null,null,3,6]
# Output: false
# Explanation: The root node's value is 5 but its right child's value is 4.
# 
# 
#
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# divide and conquer
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root, float('-inf'), float('inf'))
        
        
    def helper(self, node, low, high):
        if node is None:
            return True
        
        if node.val <= low or node.val >= high:
            return False
        
        return self.helper(node.left, low, node.val) and self.helper(node.right, node.val, high)

# in-order traversal
class Solution2(object):
    def __init__(self):
        self.pre = None
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root)

    def helper(self, cur):

        if cur is None:
            return True

        if not self.helper(cur.left):
            return False

        if (self.pre is not None and self.pre.val >= cur.val):
            return False
        self.pre = cur

        return self.helper(cur.right)