# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        results = []
        if root is None:
            return results

        node = root
        stack = []
        lastNodeVisted = None

        while(len(stack) > 0 or node is not None):
            while node is not None:
                stack.append(node)
                node = node.left
        
            peek = stack[-1] # last element
            if (peek.right is not None and lastNodeVisted != peek.right):
                node = peek.right
            else:
                results.append(peek.val)
                lastNodeVisted = peek
                stack.pop()

        return results
