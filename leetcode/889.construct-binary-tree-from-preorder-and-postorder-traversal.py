#  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/ztqhSjxYC-M

#  Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
#  If there exist multiple answers, you can return any of them.
#   
#  Example 1:
#  
#  
#  Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
#  Output: [1,2,3,4,5,6,7]
#  
#  Example 2:
#  
#  Input: preorder = [1], postorder = [1]
#  Output: [1]
#  
#   
#  Constraints:
#  
#  1 <= preorder.length <= 30
#  1 <= preorder[i] <= preorder.length
#  All the values of preorder are unique.
#  postorder.length == preorder.length
#  1 <= postorder[i] <= postorder.length
#  All the values of postorder are unique.
#  It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        post_map = {}
        for i in range(len(postorder)):
            post_map[postorder[i]] = i

        return self.helper(preorder, postorder, post_map)

    def helper(self, preorder: list, postorder: list, post_map: dict) -> TreeNode:
        n = len(preorder)
        if n == 0:
            return None

        val = preorder[0]
        node = TreeNode(val)

        if n > 1:
            r = post_map[preorder[1]]
            l = post_map[postorder[0]]
            k = r - l + 1
            node.left = self.helper(preorder[1: k + 1], postorder[0: k], post_map)
            node.right = self.helper(preorder[k + 1: n], postorder[k : n - 1], post_map)

        return node
    
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        postorder_map = {postorder[i] : i for i in range(len(postorder))}
        return self.helper(preorder, postorder_map, 0, len(preorder) - 1, 0, len(postorder) - 1)

    def helper(self, preorder:list, postorder_map:list, s0: int, e0: int, s1: int, e1: int) -> TreeNode:
        if s0 > e0:
            return None

        val = preorder[s0]
        root = TreeNode(val)
        if s0 < e0:
            left = preorder[s0 + 1]
            index = postorder_map[left]
            left_size = index - s1 + 1

            root.left = self.helper(preorder, postorder_map, s0 + 1, s0 + left_size, s1, index)
            root.right = self.helper(preorder, postorder_map, s0 + left_size + 1, e0, index + 1, e1 - 1)

        return root
 