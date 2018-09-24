# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        
        if root is None:
            return []

        queue = [(root, 0)]
        col_map = {}
        min_col = 0
        max_col = 0

        while(len(queue) > 0):
            size = len(queue)
            for i in range(size):
                node, col = queue[0]
                queue.pop(0)

                if col in col_map:
                    col_map[col].append(node.val)
                else:
                    col_map[col] = [node.val]

                if node.left is not None:
                    min_col = min(min_col, col - 1)
                    queue.append((node.left, col - 1))

                if node.right is not None:
                    max_col = max(max_col, col + 1)
                    queue.append((node.right, col + 1))

        res = []
        for i in range(min_col, max_col + 1):
            res.append(col_map[i])
        return res
