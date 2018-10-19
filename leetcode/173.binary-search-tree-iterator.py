# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.cur = root
        self.stack = []
        

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.cur is not None or len(self.stack) > 0
        

    def next(self):
        """
        :rtype: int
        """
        while self.cur is not None:
            self.stack.append(self.cur)
            self.cur = self.cur.left

        tmp = self.stack.pop()
        self.cur = tmp.right

        return tmp.val
        

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
