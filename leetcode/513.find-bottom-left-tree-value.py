#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(W)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, return the leftmost value in the last row of the tree.
#   
#  Example 1:
#  
#  
#  Input: root = [2,1,3]
#  Output: 1
#  
#  Example 2:
#  
#  
#  Input: root = [1,2,3,4,null,5,6,null,null,7]
#  Output: 7
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 104].
#  -231 <= Node.val <= 231 - 1
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        q = deque([root])
        res = None
        while len(q) > 0:
            n = len(q)
            res = q[0].val
            for i in range(n):
                node = q.popleft()
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)

        return res