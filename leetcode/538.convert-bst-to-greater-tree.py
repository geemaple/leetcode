# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):

    def __init__(self, *args, **kwargs):
        self.pre = None

    def inverse_midoder(self, node):

        if node is None:
            return

        self.inverse_midoder(node.right)

        if self.pre is not None:
            node.val += self.pre.val
            
        self.pre = node

        self.inverse_midoder(node.left)

    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.inverse_midoder(root)
        return root
        
