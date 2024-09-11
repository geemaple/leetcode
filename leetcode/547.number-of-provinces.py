#  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -

#  There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
#  A province is a group of directly or indirectly connected cities and no other cities outside of the group.
#  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
#  Return the total number of provinces.
#   
#  Example 1:
#  
#  
#  Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
#  Output: 2
#  
#  Example 2:
#  
#  
#  Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
#  Output: 3
#  
#   
#  Constraints:
#  
#  1 <= n <= 200
#  n == isConnected.length
#  n == isConnected[i].length
#  isConnected[i][j] is 1 or 0.
#  isConnected[i][i] == 1
#  isConnected[i][j] == isConnected[j][i]
#  
#  

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = set()
        count = 0
        for i in range(len(isConnected)):
            if i not in visited:
                count += 1
                self.dfs(isConnected, i, visited)

        return count

    def dfs(self, isConnected: List[List[int]], i: int, visited: set):
        visited.add(i)
        for j in range(len(isConnected)):
            if isConnected[i][j] == 1 and j not in visited:
                self.dfs(isConnected, j, visited)

class UnionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]

    def find(self, a):
        if a == self.table[a]:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)
        if root_a != root_b:
            self.table[root_a] = root_b
            return True
        return False

class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        n = len(isConnected)
        count = n
        uf = UnionFind(n)
        for i in range(n):
            for j in range(i):
                if isConnected[i][j] and uf.connect(i, j):
                    count -= 1
        return count