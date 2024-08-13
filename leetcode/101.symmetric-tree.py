#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,2,3,4,4,3]
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: root = [1,2,2,null,3,null,3]
#  Output: false
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 1000].
#  -100 <= Node.val <= 100
#  
#   
#  Follow up: Could you solve it both recursively and iteratively?

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return True

        return self.helper(root.left, root.right)

    def helper(self, left: TreeNode, right: TreeNode) -> bool:
        if left is None and right is None:
            return True

        if left is None or right is None:
            return False

        if left.val != right.val:
            return False

        return self.helper(left.left, right.right) and self.helper(left.right, right.left)