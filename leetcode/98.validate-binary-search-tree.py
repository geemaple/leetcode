# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    def __init__(self):
        self.pre = None
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root)

    def helper(self, cur):

        if cur is None:
            return True

        if not self.helper(cur.left):
            return False

        if (self.pre is not None and self.pre.val >= cur.val):
            return False
        self.pre = cur

        return self.helper(cur.right)

class Solution2(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        return self.helper(root, None, None)

    def helper(self, cur, low , high):

        if cur is None:
            return True

        if (low is not None and low.val >= cur.val) or (high is not None and high.val <= cur.val):
            return False

        return self.helper(cur.left, low, cur) and self.helper(cur.right, cur, high)