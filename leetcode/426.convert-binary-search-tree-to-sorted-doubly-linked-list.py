"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):

    def __init__(self):
        self.head = Node(0, None, None)
        self.pre = self.head

    def helper(self, cur):
        if cur is None:
            return

        self.helper(cur.left)

        self.pre.right = cur
        cur.left = self.pre
        self.pre = self.pre.right

        self.head.right.left = cur

        self.helper(cur.right)

    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        
        if root is None:
            return root

        self.helper(root)
        self.head.right.left.right = self.head.right

        return self.head.right
