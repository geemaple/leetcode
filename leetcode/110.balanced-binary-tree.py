#  Tag: Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: Recursion

#  Given a binary tree, determine if it is height-balanced.
#   
#  Example 1:
#  
#  
#  Input: root = [3,9,20,null,null,15,7]
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: root = [1,2,2,3,3,null,null,4,4]
#  Output: false
#  
#  Example 3:
#  
#  Input: root = []
#  Output: true
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 5000].
#  -104 <= Node.val <= 104
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root) != -1

    def helper(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0

        left = self.helper(node.left)
        right = self.helper(node.right)

        if left == -1 or right == -1 or abs(left - right) > 1:
            return -1

        return max(left, right) + 1
        