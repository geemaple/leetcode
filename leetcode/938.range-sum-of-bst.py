#  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(W)
#  Ref: -
#  Note: -

#  Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].
#   
#  Example 1:
#  
#  
#  Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
#  Output: 32
#  Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
#  
#  Example 2:
#  
#  
#  Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
#  Output: 23
#  Explanation: Nodes 6, 7, and 10 are in the range [6, 10]. 6 + 7 + 10 = 23.
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 2 * 104].
#  1 <= Node.val <= 105
#  1 <= low <= high <= 105
#  All Node.val are unique.
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
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        res = 0
        q = deque([root])
        while len(q) > 0:
            cur = q.popleft()
            if cur is None:
                continue

            if cur.val < low:
                q.append(cur.right)
            elif cur.val > high:
                q.append(cur.left)
            else:
                res += cur.val
                q.append(cur.left)
                q.append(cur.right)

        return res