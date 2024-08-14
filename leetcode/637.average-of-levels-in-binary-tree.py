#  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
#   
#  Example 1:
#  
#  
#  Input: root = [3,9,20,null,null,15,7]
#  Output: [3.00000,14.50000,11.00000]
#  Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
#  Hence return [3, 14.5, 11].
#  
#  Example 2:
#  
#  
#  Input: root = [3,9,20,15,7]
#  Output: [3.00000,14.50000,11.00000]
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
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        
        q = deque([root])
        res = []
        while len(q) > 0:
            n = len(q)
            total = 0
            for i in range(n):
                cur = q.popleft()
                total += cur.val
                if cur.left:
                    q.append(cur.left)
                if cur.right:
                    q.append(cur.right)

            res.append(total / n)

        return res                

