#  Tag: Divide and Conquer, Greedy, Tree, Depth-First Search, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: DSW O(n)|O(1)

#  Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
#  A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
#   
#  Example 1:
#  
#  
#  Input: root = [1,null,2,null,3,null,4,null,null]
#  Output: [2,1,3,null,null,null,4]
#  Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
#  
#  Example 2:
#  
#  
#  Input: root = [2,1,3]
#  Output: [2,1,3]
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [1, 104].
#  1 <= Node.val <= 105
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.arr = []
        self.inorder(root)
        return self.toBST(0, len(self.arr) - 1)

    def inorder(self, node: TreeNode):
        if node is None:
            return 

        self.inorder(node.left)
        self.arr.append(node)
        self.inorder(node.right)

    def toBST(self, left: int, right: int):
        if left > right:
            return 

        mid = (left + right) // 2
        root = self.arr[mid]
        root.left = self.toBST(left, mid - 1)
        root.right = self.toBST(mid + 1, right)
        return root