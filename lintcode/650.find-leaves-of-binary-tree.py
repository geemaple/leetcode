#  Tag: Binary Tree, Depth First Search/DFS, Divide and Conquer
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-366
#  Note: -

#  Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
#  
#  **Example1**
#  Input: {1,2,3,4,5}
#  Output:  `[[4, 5, 3], [2], [1]]`.
#  Explanation:
#  ```
#      1
#     / \
#    2   3
#   / \     
#  4   5    
#  ```
#  
#  **Example2**
#  Input: {1,2,3,4}
#  Output:  `[[4, 3], [2], [1]]`.
#  Explanation:
#  ```
#      1
#     / \
#    2   3
#   /
#  4 
#  ```
#  
#  

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

from collections import defaultdict
class Solution:
    """
    @param: root: the root of binary tree
    @return: collect and remove all leaves
    """
    def findLeaves(self, root):
        # write your code here
        cache = defaultdict(list)
        self.findReverseHeight(root, cache)
        res = []
        height = 0
        while height in cache:
            res.append(cache[height])
            height += 1
        
        return res

    def findReverseHeight(self, root, cache):
        if root is None:
            return -1

        lh = self.findReverseHeight(root.left, cache)
        rh = self.findReverseHeight(root.right, cache)
        height = max(lh, rh) + 1
        cache[height].append(root.val)
        return height
    
from collections import defaultdict
class Solution:
    """
    @param: root: the root of binary tree
    @return: collect and remove all leaves
    """
    def findLeaves(self, root):
        # write your code here
        res = []
        self.findReverseHeight(root, res)
        return res

    def findReverseHeight(self, root, res):
        if root is None:
            return -1

        lh = self.findReverseHeight(root.left, res)
        rh = self.findReverseHeight(root.right, res)
        height = max(lh, rh) + 1
        if height >= len(res):
            res.append([])
            
        res[height].append(root.val)
        return height
