class UnionFind(object):
    def __init__(self, n):
        self.graph = {}
        for i in range(n):
            self.graph[i] = i

    def find(self, node):
        if self.graph[node] == node:
            return node

        self.graph[node] = self.find(self.graph[node])
        return self.graph[node]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if (root_a != root_b):
            self.graph[root_a] = root_b
        

class Solution(object):
    def accountsMerge(self, accounts):
        """
        :type accounts: List[List[str]]
        :rtype: List[List[str]]
        """
        size = len(accounts)
        accountMap = {}
        uf = UnionFind(size)

        # map and union
        for i in range(size):
            for j in range(1, len(accounts[i])):
                if accounts[i][j] not in accountMap:
                    accountMap[accounts[i][j]] = i
                else:
                    k = accountMap[accounts[i][j]]
                    uf.connect(i, k)

        # find and merge
        merged = {}
        for i in range(size):
            k = uf.find(i)
            if k not in merged:
                merged[k] = set()

            for j in range(1, len(accounts[i])):
                merged[k].add(accounts[i][j])

        # results
        res = []
        for k, v in merged.iteritems():
            sub = []
            # name
            sub.append(accounts[k][0])  
            # sorted emails
            sub.extend(sorted(list(v)))
            res.append(sub)

        return res
            