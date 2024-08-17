#  Tag: Hash Table, Two Pointers, Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
#  Time: O(NH)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
#   
#  Example 1:
#  
#  
#  Input: root = [5,3,6,2,4,null,7], k = 9
#  Output: true
#  
#  Example 2:
#  
#  
#  Input: root = [5,3,6,2,4,null,7], k = 28
#  Output: false
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 104].
#  -104 <= Node.val <= 104
#  root is guaranteed to be a valid binary search tree.
#  -105 <= k <= 105
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        stack = [root]
        while len(stack) > 0:
            cur = stack.pop()
            target = self.find(root, k - cur.val)
            if target and target != cur:
                return True
            
            if cur.right:
                stack.append(cur.right)

            if cur.left:
                stack.append(cur.left)
        
        return False


    def find(self, root: TreeNode, target: int) -> TreeNode:
        if root is None:
            return None

        if target == root.val:
            return root

        if target < root.val:
            return self.find(root.left, target)
        else:
            return self.find(root.right, target)
