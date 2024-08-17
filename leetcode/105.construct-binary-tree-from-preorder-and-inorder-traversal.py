#  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
#   
#  Example 1:
#  
#  
#  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
#  Output: [3,9,20,null,null,15,7]
#  
#  Example 2:
#  
#  Input: preorder = [-1], inorder = [-1]
#  Output: [-1]
#  
#   
#  Constraints:
#  
#  1 <= preorder.length <= 3000
#  inorder.length == preorder.length
#  -3000 <= preorder[i], inorder[i] <= 3000
#  preorder and inorder consist of unique values.
#  Each value of inorder also appears in preorder.
#  preorder is guaranteed to be the preorder traversal of the tree.
#  inorder is guaranteed to be the inorder traversal of the tree.
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        
        if len(preorder) == 0:
            return None

        val = preorder[0]
        node = TreeNode(val)

        if len(preorder) > 1:
            index = inorder.index(val)
            node.left = self.buildTree(preorder[1: index + 1], inorder[:index])
            node.right = self.buildTree(preorder[index + 1:], inorder[index + 1:])

        return node
        

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        inorder_map = {inorder[i] : i for i in range(len(inorder))}
        return self.helper(preorder, inorder_map, 0, len(preorder) - 1, 0, len(inorder) - 1)
        
    def helper(self, preorder: list, inorder_map: dict, s0: int, e0: int,  s1: int, e1: int) -> TreeNode:
        if s0 > e0:
            return None

        val = preorder[s0]
        node = TreeNode(val)

        if s0 < e0:
            mid = inorder_map[val]
            left_size = mid - s1
            node.left = self.helper(preorder, inorder_map, s0 + 1, left_size + s0, s1, mid - 1)
            node.right = self.helper(preorder, inorder_map, left_size + s0 + 1, e0, mid + 1, e1)

        return node
