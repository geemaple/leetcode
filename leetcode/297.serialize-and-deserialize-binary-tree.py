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
        if root is None:
            return '[]'
        
        queue = [root]
        index = 0
        while index < len(queue):
            node = queue[index]
            if node is not None:
                queue.append(node.left)
                queue.append(node.right)
            index += 1
                
        while (len(queue) > 0 and queue[-1] is None):
            queue.pop()
        
        nodes = ['#' if n is None else str(n.val) for n in queue]
        
        return '[%s]' % (','.join(nodes))
        
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        if data == '[]':
            return None
        
        nodes = data[1: -1].split(',')
        root = TreeNode(int(nodes[0]))
        
        queue = [root]
        isLeft = True
        
        for i in range(1, len(nodes)):
            if nodes[i] != '#':
                child = TreeNode(int(nodes[i]))
                if isLeft:
                    queue[0].left = child
                else:
                    queue[0].right = child
                    
                queue.append(child)
                
            if not isLeft:
                queue.pop(0)
                
            isLeft = not isLeft
            
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))