#  Tag: Backtracking, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
#  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
#   
#  Example 1:
#  
#  
#  Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
#  Output: [[5,4,11,2],[5,8,4,5]]
#  Explanation: There are two paths whose sum equals targetSum:
#  5 + 4 + 11 + 2 = 22
#  5 + 8 + 4 + 5 = 22
#  
#  Example 2:
#  
#  
#  Input: root = [1,2,3], targetSum = 5
#  Output: []
#  
#  Example 3:
#  
#  Input: root = [1,2], targetSum = 0
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 5000].
#  -1000 <= Node.val <= 1000
#  -1000 <= targetSum <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root is None:
            return []

        res = []
        self.helper(root, [root.val], res, targetSum - root.val)
        return res

    def helper(self, node: TreeNode, paths: list, res: list, target: int):
        if node.left is None and node.right is None:
            if target == 0:
                res.append(list(paths))
            return

        if node.left is not None:
            self.helper(node.left, paths + [node.left.val], res, target - node.left.val)

        if node.right is not None:
            self.helper(node.right, paths + [node.right.val], res, target - node.right.val)