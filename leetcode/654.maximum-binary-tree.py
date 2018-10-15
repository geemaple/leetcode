# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        stack = []
        
        for k in nums:
            node = TreeNode(k)
            
            while (stack and stack[-1].val <= k):
                node.left = stack.pop()
                
            if stack:
                stack[-1].right = node
                
            stack.append(node)
        
        return stack[0]
                