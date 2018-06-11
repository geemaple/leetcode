
# O(E) E = len(edges)
class Solution(object):
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        uf = UnionFind(n)

        for pair in edges:
            x = pair[0]
            y = pair[1]

            if not uf.union(x, y):
                # has circle
                return False

        return uf.count == 1


class UnionFind(object):
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.count = n

    def find(self, x):
        if self.table[x] == x:
            return x

        self.table[x] = self.find(self.table[x])
        return self.table[x]

    def union(self, x, y):
        super_x = self.find(x)
        super_y = self.find(y)

        if super_x != super_y:
            self.table[super_x] = super_y
            self.count -= 1
            return True

        return False