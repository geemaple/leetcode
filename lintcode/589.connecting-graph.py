class ConnectingGraph:
    """
    @param: n: An integer
    """
    def __init__(self, n):
        # do intialization if necessary
        self.dict = {}
        for i in range(1, n + 1):
            self.dict[i] = i

    def find(self, node):
        if self.dict[node] == node:
            return node
        self.dict[node] = self.find(self.dict[node])
        return self.dict[node]

    """
    @param: a: An integer
    @param: b: An integer
    @return: nothing
    """
    def connect(self, a, b):
        # write your code here
        a_root = self.find(a)
        b_root = self.find(b)

        self.dict[a_root] = b_root

    """
    @param: a: An integer
    @param: b: An integer
    @return: A boolean
    """
    def query(self, a, b):
        # write your code here
        return self.find(a) == self.find(b)