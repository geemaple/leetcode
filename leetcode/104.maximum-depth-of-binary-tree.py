#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: Recursion

#  Given the root of a binary tree, return its maximum depth.
#  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
#   
#  Example 1:
#  
#  
#  Input: root = [3,9,20,null,null,15,7]
#  Output: 3
#  
#  Example 2:
#  
#  Input: root = [1,null,2]
#  Output: 2
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 104].
#  -100 <= Node.val <= 100
#  
#  

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        height = 0
        queue = deque([root])
        while len(queue) > 0:
            height += 1
            size = len(queue)

            for _ in range(size):
                node = queue.popleft()
                if node.left:
                    queue.append(node.left)

                if node.right:
                    queue.append(node.right)

        return height

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0

        return max(self.maxDepth(root.left), self.maxDepth(root.right)) + 1
        