# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self, *args, **kwargs):
        self.heightMap = {}

    def node_height(self, cur):
        if cur is None:
            return 0

        height = max(self.node_height(cur.left) + 1, self.node_height(cur.right) + 1)
        if height in self.heightMap:
            self.heightMap[height].append(cur.val)
        else:
            self.heightMap[height] = [cur.val]

        return height

    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        max_height = self.node_height(root)
        res = []

        for i in range(1, max_height + 1):
            res.append(self.heightMap[i])

        return res
        
