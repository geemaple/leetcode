class ConnectingGraph3:

    def __init__(self, n):
        self.size = n
        self.graph = {}

        for i in range(1, n + 1):
            self.graph[i] = i

    def find(self, node):
        if self.graph[node] == node:
            return node

        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]

    """
    @param a: An integer
    @param b: An integer
    @return: nothing
    """
    def connect(self, a, b):
        # write your code here
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.graph[root_a] = root_b
            self.size -= 1

    """
    @return: An integer
    """
    def query(self):
        # write your code here
        return self.size