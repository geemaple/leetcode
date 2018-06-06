# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Your runtime beats 31 % of python submissions
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        low = float('-inf')
        high = float('inf')
        return self.helper(root, low, high)

    def helper(self, node, low , high):

        if node is None:
            return True

        if node.val <= low or node.val >= high:
            return False

        left = self.helper(node.left, low, node.val)
        if not left:
            return left

        right = self.helper(node.right, node.val, high)
        if not right:
            return right

        return True