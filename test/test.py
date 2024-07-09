from typing import List
import collections
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
        if n == 1:
            return [0]

        graph = collections.defaultdict(list)
        degree = collections.defaultdict(int)
        for i, j in edges:
            graph[i].append(j)
            graph[j].append(i)
            degree[i] += 1
            degree[j] += 1

        q = collections.deque()
        for node in range(n):
            if degree[node] == 1:
                q.append(node)

        remain = n
        while len(q) > 0:
            if remain <= 2:
                break
            size = len(q)
            for _ in range(size):
                cur = q.popleft()
                for n in graph[cur]:
                    degree[n] -= 1
                    if degree[n] == 1:
                        q.append(n)

            remain -= size

        return list(q)


s = Solution()
t = []
res = s.findMinHeightTrees(3, [[0,1],[0,2]])
print(res)