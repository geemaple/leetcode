# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def __init__(self, *args, **kwargs):
        self.newRoot = None

    def invert(self, node):
        if node is None:
            return

        if node.left is None:
            self.newRoot = node
        else:
            self.invert(node.left)

            node.left.left = node.right
            node.left.right = node
            node.left = None
            node.right = None
        
    def upsideDownBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.invert(root)
        return self.newRoot
