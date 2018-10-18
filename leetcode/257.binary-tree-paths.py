# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if root is None:
            return []
        
        res = []
        self.dfs(root, '', res)
        return res
        
    def dfs(self, cur, path, ans):
        path += str(cur.val)
        
        if cur.left is None and cur.right is None:
            ans.append(path)
            
        if cur.left is not None:
            self.dfs(cur.left, path + '->', ans)
            
        if cur.right is not None:
            self.dfs(cur.right, path + '->', ans)
        