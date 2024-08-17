#  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
#   
#  Example 1:
#  
#  
#  Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
#  Output: [3,9,20,null,null,15,7]
#  
#  Example 2:
#  
#  Input: inorder = [-1], postorder = [-1]
#  Output: [-1]
#  
#   
#  Constraints:
#  
#  1 <= inorder.length <= 3000
#  postorder.length == inorder.length
#  -3000 <= inorder[i], postorder[i] <= 3000
#  inorder and postorder consist of unique values.
#  Each value of postorder also appears in inorder.
#  inorder is guaranteed to be the inorder traversal of the tree.
#  postorder is guaranteed to be the postorder traversal of the tree.
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        if len(postorder) == 0:
            return None

        val = postorder[-1]
        root = TreeNode(val)
        if len(postorder) > 1:
            mid = inorder.index(val)
            root.left = self.buildTree(inorder[: mid], postorder[: mid])
            root.right = self.buildTree(inorder[mid + 1:], postorder[mid : -1])

        return root

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        inorder_map = {inorder[i]: i for i in range(len(inorder))}
        return self.helper(inorder_map, postorder, 0, len(inorder) - 1, 0, len(postorder) - 1)

    def helper(self, inorder_map: list, postorder: list, s0: int, e0: int, s1: int, e1: int) -> TreeNode:
        if s1 > e1:
            return None

        val = postorder[e1]
        root = TreeNode(val)
        if s1 < e1:
            mid = inorder_map[val]
            left_size = mid - s0
            root.left = self.helper(inorder_map, postorder, s0, mid - 1, s1, left_size + s1 - 1)
            root.right = self.helper(inorder_map, postorder, mid + 1, e0, left_size + s1, e1 - 1)
        return root