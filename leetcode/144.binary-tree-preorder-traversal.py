#  Tag: Stack, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: PreOrder

#  Given the root of a binary tree, return the preorder traversal of its nodes' values.
#   
#  Example 1:
#  
#  
#  Input: root = [1,null,2,3]
#  Output: [1,2,3]
#  
#  Example 2:
#  
#  Input: root = []
#  Output: []
#  
#  Example 3:
#  
#  Input: root = [1]
#  Output: [1]
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 100].
#  -100 <= Node.val <= 100
#  
#   
#  Follow up: Recursive solution is trivial, could you do it iteratively?
#  

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        self.helper(root, results)
        return results

    def helper(self, node: TreeNode, results:List[int]):
        if node is None:
            return

        results.append(node.val)
        self.helper(node.left, results)
        self.helper(node.right, results)


class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

        if root is None:
            return []

        results = []
        stack = [root]

        while (len(stack) > 0):
            node = stack.pop()
            results.append(node.val)

            if node.right:
                stack.append(node.right)

            if node.left:
                stack.append(node.left)

        return results