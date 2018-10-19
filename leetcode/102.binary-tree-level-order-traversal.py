# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        
        q = [root]
        res = []
        
        while len(q) > 0:
            size = len(q)
            ans = []
            for i in range(size):
                tmp = q.pop(0)
                ans.append(tmp.val)
                
                if tmp.left:
                    q.append(tmp.left)
                    
                if tmp.right:
                    q.append(tmp.right)
            
            res.append(ans)
                
        return res
                