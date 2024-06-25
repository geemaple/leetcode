#  Tag: Tree, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(Width)
#  Ref: -
#  Note: Level

#  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
#   
#  Example 1:
#  
#  
#  Input: root = [3,9,20,null,null,15,7]
#  Output: [[3],[9,20],[15,7]]
#  
#  Example 2:
#  
#  Input: root = [1]
#  Output: [[1]]
#  
#  Example 3:
#  
#  Input: root = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 2000].
#  -1000 <= Node.val <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []

        res = []
        q = deque([root])
        while len(q) > 0:
            size = len(q)
            level = []
            for i in range(size):
                node = q.popleft()
                level.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(level)
        return res
