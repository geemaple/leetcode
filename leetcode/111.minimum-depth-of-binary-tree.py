#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(W)
#  Ref: -
#  Note: -

#  Given a binary tree, find its minimum depth.
#  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
#  Note: A leaf is a node with no children.
#   
#  Example 1:
#  
#  
#  Input: root = [3,9,20,null,null,15,7]
#  Output: 2
#  
#  Example 2:
#  
#  Input: root = [2,null,3,null,4,null,5,null,6]
#  Output: 5
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 105].
#  -1000 <= Node.val <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        if root.left is None:
            return self.minDepth(root.right) + 1

        if root.right is None:
            return self.minDepth(root.left) + 1

        return min(self.minDepth(root.left), self.minDepth(root.right)) + 1
    
from collections import deque
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        q = deque([root])
        level = 0
        while len(q) > 0:
            count = len(q)
            level += 1
            for i in range(count):
                cur = q.popleft()
                if cur.left is None and cur.right is None:
                    return level

                if cur.left:
                    q.append(cur.left)

                if cur.right:
                    q.append(cur.right)