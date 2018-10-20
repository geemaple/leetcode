# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        if root is None:
            return []

        res = []
        q = [root]
        backward = False

        while len(q) > 0:
            
            ans = []
            size = len(q)
            for i in range(size):
                tmp = q.pop(0)
                ans.append(tmp.val)

                if tmp.left is not None:
                    q.append(tmp.left)

                if tmp.right is not None:
                    q.append(tmp.right)

            if backward:
                ans = ans[::-1]

            res.append(ans)
            backward = not backward

        return res
