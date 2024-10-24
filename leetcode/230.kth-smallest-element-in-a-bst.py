#  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(K)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
#   
#  Example 1:
#  
#  
#  Input: root = [3,1,4,null,2], k = 1
#  Output: 1
#  
#  Example 2:
#  
#  
#  Input: root = [5,3,6,2,4,null,null,1], k = 3
#  Output: 3
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is n.
#  1 <= k <= n <= 104
#  0 <= Node.val <= 104
#  
#   
#  Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        cur = root
        stack = []

        count = 0
        while (cur or len(stack) > 0):
            while cur:
                stack.append(cur)
                cur = cur.left

            cur = stack.pop()
            count += 1
            if count == k:
                return cur.val

            cur = cur.right

# follow-up
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.size = 1  # size of the subtree rooted at this node
        self.left = None
        self.right = None

class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        left_size = self.get_size(root.left)

        if k <= left_size:
            return self.kthSmallest(root.left, k)
        elif k == left_size + 1:
            return root.val
        else:
            return self.kthSmallest(root.right, k - left_size - 1)

    def get_size(self, node: TreeNode) -> int:
        return node.size if node else 0