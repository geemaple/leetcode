#  Tag: Stack, Tree, Depth-First Search, Linked List, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: PreOrder

#  Given the root of a binary tree, flatten the tree into a "linked list":
#  
#  The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
#  The "linked list" should be in the same order as a pre-order traversal of the binary tree.
#  
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,5,3,4,null,6]
#  Output: [1,null,2,null,3,null,4,null,5,null,6]
#  
#  Example 2:
#  
#  Input: root = []
#  Output: []
#  
#  Example 3:
#  
#  Input: root = [0]
#  Output: [0]
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 2000].
#  -100 <= Node.val <= 100
#  
#   
#  Follow up: Can you flatten the tree in-place (with O(1) extra space)?

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if root is None:
            return
            
        stack = [root]
        last = None

        while (len(stack) > 0):
            node = stack.pop()
            if last:
                last.left = None
                last.right = node
            last = node

            if node.right:
                stack.append(node.right)

            if node.left:
                stack.append(node.left)


class Solution(object):
    
    def __init__(self):
        self.pre = None
    
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.helper(root)
        
    def helper(self, node: Optional[TreeNode]):
        if node is None:
            return
        
        left = node.left
        right = node.right
        
        if self.pre:
            self.pre.right = node
        node.left = None
        self.pre = node
        
        self.helper(left)
        self.helper(right)