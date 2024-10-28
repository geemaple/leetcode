#  Tag: String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Search Tree, Binary Tree
#  Time: O(N)
#  Space: O(H)
#  Ref: -
#  Note: -

#  Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
#  Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.
#  The encoded string should be as compact as possible.
#   
#  Example 1:
#  Input: root = [2,1,3]
#  Output: [2,1,3]
#  Example 2:
#  Input: root = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 104].
#  0 <= Node.val <= 104
#  The input tree is guaranteed to be a binary search tree.
#  
#  

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Codec:

    def serialize(self, root: Optional[TreeNode]) -> str:
        """Encodes a tree to a single string.
        """
        res = []
        self.preorder(root, res)
        return ','.join([str(x) for x in res])
   
    def preorder(self, node: TreeNode, res: list):
        if node is None:
            return

        res.append(node.val)
        self.preorder(node.left, res)
        self.preorder(node.right, res)

    def deserialize(self, data: str) -> Optional[TreeNode]:
        """Decodes your encoded data to tree.
        """
        if len(data) == 0:
            return None

        nodes = list(map(int, data.split(',')))
        return self.construct(deque(nodes), float('-inf'), float('inf'))

    def construct(self, q: deque, min_val: float, max_val: float) -> TreeNode:
        if len(q) == 0 or q[0] < min_val or q[0] > max_val: 
            return None

        val = q.popleft()
        root = TreeNode(val)

        root.left = self.construct(q, min_val, val)
        root.right = self.construct(q, val, max_val)

        return root

# Your Codec object will be instantiated and called as such:
# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# tree = ser.serialize(root)
# ans = deser.deserialize(tree)
# return ans