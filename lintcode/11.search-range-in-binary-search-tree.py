#  Tag: Binary Tree, Divide and Conquer, Binary Search Tree, Depth First Search/DFS
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: InOrder

#  Given a binary search tree and a range `[k1, k2]`, return node values within a given range in ascending order.
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  tree = {5}
#  k1 = 6
#  k2 = 10
#  ``` 
#  Output:  
#  ``` 
#  []
#  ``` 
#  Explanation:  
#  
#  No number between 6 and 10
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  tree = {20,8,22,4,12}
#  k1 = 10
#  k2 = 22
#  ``` 
#  Output:  
#  ``` 
#  [12,20,22]
#  ``` 
#  Explanation:  
#  
#  [12,20,22] between 10 and 22
#  
#  

from typing import (
    List,
)
from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: param root: The root of the binary search tree
    @param k1: An integer
    @param k2: An integer
    @return: return: Return all keys that k1<=key<=k2 in ascending order
    """
    def search_range(self, root: TreeNode, k1: int, k2: int) -> List[int]:
        # write your code here
        stack = []
        node = root
        res = []

        while (len(stack) > 0 or node):
            while node:
                if node.val < k1:
                    node = node.right
                else:
                    stack.append(node)
                    node = node.left

            if len(stack) > 0:
                node = stack.pop()
                if node.val > k2:
                    break

                if node.val >= k1:
                    res.append(node.val)

                node = node.right
        return res


class Solution:
    """
    @param root: param root: The root of the binary search tree
    @param k1: An integer
    @param k2: An integer
    @return: return: Return all keys that k1<=key<=k2 in ascending order
    """
    def search_range(self, root: TreeNode, low: int, high: int) -> List[int]:
        result = []
        def inOrderTraversal(node):
            if node is None:
                return
            if node.val > low:
                inOrderTraversal(node.left)
            if low <= node.val <= high:
                result.append(node.val)
            if node.val < high:
                inOrderTraversal(node.right)

        inOrderTraversal(root)
        return result