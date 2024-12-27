#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(W)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, return the maximum width of the given tree.
#  The maximum width of a tree is the maximum width among all levels.
#  The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
#  It is guaranteed that the answer will in the range of a 32-bit signed integer.
#   
#  Example 1:
#  
#  
#  Input: root = [1,3,2,5,3,null,9]
#  Output: 4
#  Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
#  
#  Example 2:
#  
#  
#  Input: root = [1,3,2,5,null,null,9,6,null,7]
#  Output: 7
#  Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
#  
#  Example 3:
#  
#  
#  Input: root = [1,3,2,5]
#  Output: 2
#  Explanation: The maximum width exists in the second level with length 2 (3,2).
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 3000].
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
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append((root, 0))
        res = 0

        while len(q) > 0:
            size = len(q)
            start = q[0][1]
            end = q[-1][1]

            res = max(res, end - start + 1)
            for i in range(size):
                cur, index = q.popleft()
                index -= start

                if cur.left:
                    q.append((cur.left, 2 * index + 1))

                if cur.right:
                    q.append((cur.right, 2 * index + 2))

        return res