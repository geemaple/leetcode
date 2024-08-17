#  Tag: Stack, Tree, Depth-First Search, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: PostOrder

#  Given the root of a binary tree, return the postorder traversal of its nodes' values.
#   
#  Example 1:
#  
#  
#  Input: root = [1,null,2,3]
#  Output: [3,2,1]
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
#  The number of the nodes in the tree is in the range [0, 100].
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
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        results = []
        self.helper(root, results)
        return results

    def helper(self, node: TreeNode, results:List[int]):
        if node is None:
            return

        self.helper(node.left, results)
        self.helper(node.right, results)
        results.append(node.val)
        

class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        cur = root
        stack = []
        pre = None
        res = []
        while cur or len(stack) > 0:
            while cur is not None:
                stack.append(cur)
                cur = cur.left

            cur = stack[-1]
            if cur.right is not None and cur.right != pre:
                cur = cur.right
            else:
                res.append(cur.val)
                stack.pop()
                pre = cur
                cur = None
                
        return res