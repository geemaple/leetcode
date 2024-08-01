#  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: BST

#  Given the root of a binary tree, determine if it is a valid binary search tree (BST).
#  A valid BST is defined as follows:
#  
#  The left subtree of a node contains only nodes with keys less than the node's key.
#  The right subtree of a node contains only nodes with keys greater than the node's key.
#  Both the left and right subtrees must also be binary search trees.
#  
#   
#  Example 1:
#  
#  
#  Input: root = [2,1,3]
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: root = [5,1,4,null,null,3,6]
#  Output: false
#  Explanation: The root node's value is 5 but its right child's value is 4.
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 104].
#  -231 <= Node.val <= 231 - 1
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root, float('-inf'), float('inf'))


    def helper(self, node: Optional[TreeNode], low: int, high: int) -> bool:
        if node is None:
            return True
        
        if node.val <= low or node.val >= high:
            return False
        
        return self.helper(node.left, low, node.val) and self.helper(node.right, node.val, high)

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        stack = []
        node = root
        val = float('-inf')

        while (len(stack) > 0 or node):
            while node:
                stack.append(node)
                node = node.left

            node = stack.pop()
            if val < node.val:
                val = node.val
            else:
                return False

            node = node.right

        return True