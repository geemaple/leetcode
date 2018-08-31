'''
Definition for a Connection
class Connection:

    def __init__(self, city1, city2, cost):
        self.city1, self.city2, self.cost = city1, city2, cost
'''

class UnionFind(object):
    def __init__(self, n):
        self.size = n
        self.graph = {}
        for i in range(n):
            self.graph[i] = i
    
    def find(self, node):
        if self.graph[node] == node:
            return node

        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]

    def query(self, a, b):
        return self.find(a) == self.find(b)

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a != root_b:
            self.size -= 1
            self.graph[root_a] = root_b

    def all_connected(self):
        return self.size == 1

def comp(a, b):
    if a.cost != b.cost:
        return a.cost - b.cost
    
    if a.city1 != b.city1:
        if a.city1 < b.city1:
            return -1
        else:
            return 1

    if a.city2 == b.city2:
        return 0
    elif a.city2 < b.city2:
        return -1
    else:
        return 1

class Solution:
    # @param {Connection[]} connections given a list of connections
    # include two cities and cost
    # @return {Connection[]} a list of connections from results

    def lowestCost(self, connections):
        # Write your code here
        connections.sort(cmp=comp)

        cityMap = {}
        count = 0
        for conn in connections:
            if conn.city1 not in cityMap:
                cityMap[conn.city1] = count
                count += 1

            if conn.city2 not in cityMap:
                cityMap[conn.city2] = count
                count += 1

        uf = UnionFind(count)
        res = []
        for conn in connections:
            city1 = cityMap[conn.city1]
            city2 = cityMap[conn.city2]

            if not uf.query(city1, city2):
                uf.connect(city1, city2)
                res.append(conn)

        return res if uf.all_connected() else []