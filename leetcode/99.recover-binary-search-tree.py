#  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
#   
#  Example 1:
#  
#  
#  Input: root = [1,3,null,null,2]
#  Output: [3,1,null,null,2]
#  Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
#  
#  Example 2:
#  
#  
#  Input: root = [3,1,4,null,null,2]
#  Output: [2,1,4,null,null,3]
#  Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [2, 1000].
#  -231 <= Node.val <= 231 - 1
#  
#   
#  Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        first, second, pre = self.helper(root, None, None, None)
        first.val, second.val = second.val, first.val

    def helper(self, node: TreeNode, first: TreeNode, second: TreeNode, pre: TreeNode):
        if node is None:
            return first, second, pre

        first, second, pre = self.helper(node.left, first, second, pre)

        if pre and pre.val > node.val:
            if not first:
                first = pre
            second = node

        pre = node
        return self.helper(node.right, first, second, pre)

class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = []
        cur = root
        pre = None
        first = None
        second = None

        while cur or len(stack) > 0:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            if pre is not None and pre.val > cur.val:
                if first is None:
                    first = pre
                second = cur

            pre = cur
            cur = cur.right

        first.val, second.val = second.val, first.val