# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    
    def __init__(self):
        self.pre = None
    
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.helper(root)
        
    def helper(self, cur):
        if cur is None:
            return
        
        left = cur.left
        right = cur.right
        
        if self.pre is not None:
            self.pre.right = cur
        cur.left = None
        self.pre = cur
        
        self.helper(left)
        self.helper(right)