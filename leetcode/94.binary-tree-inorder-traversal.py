#  Tag: Stack, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: InOrder

#  Given the root of a binary tree, return the inorder traversal of its nodes' values.
#   
#  Example 1:
#  
#  
#  Input: root = [1,null,2,3]
#  Output: [1,3,2]
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

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        self.helper(root, results)
        return results

    def helper(self, node: TreeNode, results:List[int]):
        if node is None:
            return

        self.helper(node.left, results)
        results.append(node.val)
        self.helper(node.right, results)


class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        cur = root
        stack = []
        res = []

        while cur or len(stack) > 0:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            res.append(cur.val)

            cur = cur.right

        return res