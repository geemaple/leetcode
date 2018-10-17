# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.res = 0
    
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.helper(root)
        return self.res
        
    def helper(self, cur):
        if cur is None:
            return 0
        
        left = self.helper(cur.left)
        right = self.helper(cur.right)
        
        left = left + 1 if cur.left is not None and cur.left.val == cur.val else 0
        right = right + 1 if cur.right is not None and cur.right.val == cur.val else 0
            
        self.res = max(self.res, left + right)
            
        return max(left, right)
        