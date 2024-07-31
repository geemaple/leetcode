#  Tag: Tree, Depth-First Search, Breadth-First Search, Design, String, Binary Tree
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: Serialization

#  Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
#  Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
#  Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
#   
#  Example 1:
#  
#  
#  Input: root = [1,2,3,null,null,4,5]
#  Output: [1,2,3,null,null,4,5]
#  
#  Example 2:
#  
#  Input: root = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the tree is in the range [0, 104].
#  -1000 <= Node.val <= 1000
#  
#  

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        q = [root]
        index = 0
        while index < len(q):
            node = q[index]
    
            if node:
                q.append(node.left)
                q.append(node.right)

            index += 1
            
        while len(q) > 0 and q[-1] is None:
            q.pop()

        res = ['#' if n is None else str(n.val) for n in q]
        return '[' + ','.join(res) + ']'

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if len(data) == 2:
            return None
        
        nodes = data[1:-1].split(',')
        root = TreeNode(int(nodes[0]))
        q = [root]
        index = 0
        isLeft = True
        for i in range(1, len(nodes)):
            val = nodes[i]

            if val != '#':
                node = q[index]
                child = TreeNode(int(val))

                if isLeft:
                    node.left = child
                else:
                    node.right = child

                q.append(child)

            if not isLeft:
                index += 1

            isLeft = not isLeft

        return root

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))