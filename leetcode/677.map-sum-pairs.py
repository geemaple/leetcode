class TrieNode(object):
    def __init__(self):
        self.children = {}
        self.is_word = False
        self.sum = 0


class MapSum(object):
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode()

    def insert(self, key, val):
        """
        :type key: str
        :type val: int
        :rtype: void
        """
        node = self.root
        for c in key:
            if c not in node.children:
                node.children[c] = TrieNode()

            node = node.children[c]

        node.is_word = True
        node.sum = val
        

    def sum(self, prefix):
        """
        :type prefix: str
        :rtype: int
        """
        node = self.root
        for c in prefix:
            if c not in node.children:
                return 0

            node = node.children[c]

        res = 0
        stack = [node]
        while(len(stack) > 0):
            node = stack.pop()
            if node.is_word:
                res += node.sum

            for k, v in node.children.iteritems():
                stack.append(v)
            
        return res     


# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
