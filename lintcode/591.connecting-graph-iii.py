#  Tag: Union Find
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given `n` nodes in a graph, denoted `1` through `n`.
#  `ConnectingGraph3(n)` creates `n` nodes, and at the beginning there are no edges in the graph.
#  
#  You need to support the following method:
#  1.
#  `connect(a, b)`, an edge to connect node a and node b
#  2.
#  `query()`, Returns the number of connected component in the graph
#  
#  Example 1:
#  ```
#  Input:
#  ConnectingGraph3(5)
#  query()
#  connect(1, 2)
#  query()
#  connect(2, 4)
#  query()
#  connect(1, 4)
#  query()
#  
#  Output:[5,4,3,3]
#  
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  ConnectingGraph3(6)
#  query()
#  query()
#  query()
#  query()
#  query()
#  
#  
#  Output:
#  [6,6,6,6,6]
#  
#  
#  ```
#  
#  A single node is also considered a connected component.

class ConnectingGraph3:
    """
    @param a: An integer
    @param b: An integer
    @return: nothing
    """
    def __init__(self, n):
        # initialize your data structure here.
        self.table = [i for i in range(n + 1)]
        self.count = n
    
    def connect(self, a, b):
        # write your code here
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.count -= 1
            self.table[root_a] = root_b

    def find(self, a):
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]
    """
    @return: An integer
    """
    def query(self):
        # write your code here
        return self.count