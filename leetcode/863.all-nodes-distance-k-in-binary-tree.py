#  Tag: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
#  You can return the answer in any order.
#   
#  Example 1:
#  
#  
#  Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
#  Output: [7,4,1]
#  Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
#  
#  Example 2:
#  
#  Input: root = [1], target = 1, k = 3
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 500].
#  0 <= Node.val <= 500
#  All the values Node.val are unique.
#  target is the value of one of the nodes in the tree.
#  0 <= k <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import deque, defaultdict
class Solution:
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        graph = defaultdict(list)
        q = deque([root])
        while len(q) > 0:
            cur = q.popleft()
            if cur.left:
                graph[cur.val].append(cur.left.val)
                graph[cur.left.val].append(cur.val)
                q.append(cur.left)

            if cur.right:
                graph[cur.val].append(cur.right.val)
                graph[cur.right.val].append(cur.val)
                q.append(cur.right)

        res = []
        visited = set([target.val])
        q = deque([target.val])
        level = 0
        while len(q) > 0:
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                if level == k:
                    res.append(cur)

                for child in graph[cur]:
                    if child not in visited:
                        visited.add(child)
                        q.append(child)

            level += 1
        return res