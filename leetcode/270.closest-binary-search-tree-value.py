# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        cur = root
        closest = cur.val
        
        while cur is not None:
            if abs(closest - target) > abs(cur.val - target):
                closest = cur.val
        
            if cur.val - target > 0:
                cur = cur.left
            else:
                cur = cur.right
                
        return closest
        