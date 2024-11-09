#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(W)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,3,null,5,null,4]
#  Output: [1,3,4]
#  
#  Example 2:
#  
#  Input: root = [1,null,3]
#  Output: [1,3]
#  
#  Example 3:
#  
#  Input: root = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 100].
#  -100 <= Node.val <= 100
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
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []

        res = []
        q = deque([root])
        while len(q) > 0:
            size = len(q)
            for i in range(size):
                cur = q.popleft()
                if cur.left is not None:
                    q.append(cur.left)
                if cur.right is not None:
                    q.append(cur.right)

                if i == size - 1:
                    res.append(cur.val)

        return res
    
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        self.helper(root, 1, res)
        return res

    def helper(self, node: TreeNode, level: int, res:list):
        if node is None:
            return

        if len(res) < level:
            res.append(node.val)

        self.helper(node.right, level + 1, res)
        self.helper(node.left, level + 1, res)