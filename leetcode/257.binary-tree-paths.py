#  Category: Tree, Depth-First Search, String, Backtracking, Binary Tree
#  Time: O(N)
#  Space: O(Height)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, return all root-to-leaf paths in any order.
#  A leaf is a node with no children.
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,3,null,5]
#  Output: ["1->2->5","1->3"]
#  
#  Example 2:
#  
#  Input: root = [1]
#  Output: ["1"]
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 100].
#  -100 <= Node.val <= 100
#  
#  

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        if root is None:
            return []

        results = []
        path = ''
        self.helper(root, path, results)
        return results
    
    def helper(self, node: Optional[TreeNode], path: str, results: List[str]):

        path += str(node.val)

        if node.left is None and node.right is None:
            results.append(path)
            return

        if node.left:
            self.helper(node.left, path + '->', results)
        if node.right:
            self.helper(node.right, path + '->', results)