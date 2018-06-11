# union-find
class ConnectingGraph3:
    """
    @param: n: An integer
    """
    def __init__(self, n):
        # do intialization if necessary
        self.count = n
        self.table = [i for i in range(n + 1)]

    def find(self, x):
        if self.table[x] == x:
            return x
            
        self.table[x] = self.find(self.table[x])
        return self.table[x]

    """
    @param: a: An integer
    @param: b: An integer
    @return: nothing
    """
    def connect(self, a, b):
        # write your code here
        superA = self.find(a)
        superB = self.find(b)
        if superA != superB:
            self.count -= 1
            self.table[superA] = superB
        
    """
    @return: An integer
    """
    def query(self):
        # write your code here
        return self.count
