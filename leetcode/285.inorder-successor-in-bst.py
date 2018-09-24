# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderSuccessor(self, root, p):
        """
        :type root: TreeNode
        :type p: TreeNode
        :rtype: TreeNode
        """
        
        if root is None or p is None:
            return None

        cur = root
        ans = None
        while(cur.val != p.val):
            if cur.val < p.val:
                cur = cur.right

            if cur.val > p.val:
                ans = cur
                cur = cur.left
        
        if p.right is not None:
            cur = p.right
            while(cur.left):
                cur = cur.left
            ans = cur

        return ans