#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
#   
#  Example 1:
#  
#  
#  Input: root = [4,2,6,1,3]
#  Output: 1
#  
#  Example 2:
#  
#  
#  Input: root = [1,0,48,null,null,12,49]
#  Output: 1
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [2, 104].
#  0 <= Node.val <= 105
#  
#   
#  Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.pre = None
        self.res = float('inf')
        self.helper(root)
        return self.res

    def helper(self, node: TreeNode):
        if node is None:
            return

        self.helper(node.left)
        if self.pre is not None:
            self.res = min(self.res, abs(self.pre.val - node.val))
        self.pre = node
        self.helper(node.right)

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        return self.helper(root, None, float('inf'))[1]
    
    def helper(self, node: Optional[TreeNode], pre: Optional[TreeNode], res: int) -> (TreeNode, int):
        if node is None:
            return pre, res
        
        pre, res = self.helper(node.left, pre, res)
    
        if pre is not None:
            res = min(res, abs(pre.val - node.val))
        pre = node

        return self.helper(node.right, pre, res)