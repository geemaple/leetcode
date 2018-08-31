class ConnectingGraph2:
    """
    @param: n: An integer
    """
    def __init__(self, n):
        # do intialization if necessary
        self.graph = {}
        self.size = {}

        for i in range(1, n + 1):
            self.size[i] = 1
            self.graph[i] = i
    
    def find(self, node):
        if self.graph[node] == node:
            return node

        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]

    """
    @param: a: An integer
    @param: b: An integer
    @return: nothing
    """
    def connect(self, a, b):
        # write your code here
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.graph[root_a] = root_b
            self.size[root_b] += self.size[root_a]


    """ 
    @param: a: An integer
    @return: An integer
    """
    def query(self, a):
        # write your code here
        root_a = self.find(a)
        return self.size[root_a]