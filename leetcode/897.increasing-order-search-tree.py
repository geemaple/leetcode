#  Tag: Stack, Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.
#   
#  Example 1:
#  
#  
#  Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
#  Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
#  
#  Example 2:
#  
#  
#  Input: root = [5,1,7]
#  Output: [1,null,5,null,7]
#  
#   
#  Constraints:
#  
#  The number of nodes in the given tree will be in the range [1, 100].
#  0 <= Node.val <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        return self.helper(root, None)
        
    def helper(self, root: TreeNode, tail: TreeNode) -> TreeNode:

        if root is None:
            return tail

        res = self.helper(root.left, root)
        root.left = None
        root.right = self.helper(root.right, tail)
        return res

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        cur = root
        pre = None
        stack = []
        head = None
        while cur or len(stack) > 0:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            cur.left = None
            if pre is not None:
                pre.right = cur

            if head is None:
                head = cur

            pre = cur
            cur = cur.right

        return head
