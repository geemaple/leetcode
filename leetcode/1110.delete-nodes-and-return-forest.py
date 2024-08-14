#  Tag: Array, Hash Table, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, each node in the tree has a distinct value.
#  After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
#  Return the roots of the trees in the remaining forest. You may return the result in any order.
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
#  Output: [[1,2,null,4],[6],[7]]
#  
#  Example 2:
#  
#  Input: root = [1,2,4,null,3], to_delete = [3]
#  Output: [[1,2,4]]
#  
#   
#  Constraints:
#  
#  The number of nodes in the given tree is at most 1000.
#  Each node has a distinct value between 1 and 1000.
#  to_delete.length <= 1000
#  to_delete contains distinct values between 1 and 1000.
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        delete = set(to_delete)
        res = []
        root = self.helper(root, delete, res)
        if root:
            res.append(root)
        return res

    def helper(self, node: TreeNode, delete: set, res: list) -> TreeNode:
        if node is None:
            return None

        node.left = self.helper(node.left, delete, res)
        node.right = self.helper(node.right, delete, res)

        if node.val in delete:
            if node.left:
                res.append(node.left)

            if node.right:
                res.append(node.right)

            return None

        return node