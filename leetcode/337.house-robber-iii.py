#  Tag: Dynamic Programming, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
#  Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
#  Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
#   
#  Example 1:
#  
#  
#  Input: root = [3,2,3,null,3,null,1]
#  Output: 7
#  Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
#  
#  Example 2:
#  
#  
#  Input: root = [3,4,5,1,3,null,1]
#  Output: 9
#  Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 104].
#  0 <= Node.val <= 104
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
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        res = self.helper(root)
        return max(res)

    def helper(self, node: TreeNode) -> list:
        if node is None:
            return [0, 0]

        left = self.helper(node.left)
        right = self.helper(node.right)

        rob = node.val + left[1] + right[1]
        not_rob = max(left) + max(right)

        return [rob, not_rob]
    
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        return self.helper(root, {})

    def helper(self, node: TreeNode, cache: dict) -> int:
        if node is None:
            return 0

        if node not in cache:
            rob = node.val
            if node.left:
                rob += self.helper(node.left.left, cache) + self.helper(node.left.right, cache)

            if node.right:
                rob += self.helper(node.right.left, cache) + self.helper(node.right.right, cache)

            not_rob = self.helper(node.left, cache) + self.helper(node.right, cache)

            cache[node] = max(rob, not_rob)

        return cache[node]