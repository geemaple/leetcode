# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return []
        
        stack = []
        stack.append(root)
        res = []
        
        while(len(stack)):
            cur = stack.pop()
            res.append(cur.val)
            
            if cur.right is not None:
                stack.append(cur.right)
                
            if cur.left is not None:
                stack.append(cur.left)
                
        return res