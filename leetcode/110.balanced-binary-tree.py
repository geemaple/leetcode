# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root) != -1
        
    def helper(self, node):

        if node is None:
            return 0

        left = self.helper(node.left)
        right = self.helper(node.right)

        if left == -1 or right == -1:
            return -1

        return -1 if abs(left - right) > 1 else max(left, right) + 1