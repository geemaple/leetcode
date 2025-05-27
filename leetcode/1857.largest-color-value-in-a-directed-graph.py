#  Tag: Hash Table, Dynamic Programming, Graph, Topological Sort, Memoization, Counting
#  Time: O(N + M)
#  Space: O(N + M)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/_zRcPgszGK8

#  There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
#  You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
#  A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
#  Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.
#   
#  Example 1:
#  
#  
#  Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
#  Output: 3
#  Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
#  
#  Example 2:
#  
#  
#  Input: colors = "a", edges = [[0,0]]
#  Output: -1
#  Explanation: There is a cycle from 0 to 0.
#  
#   
#  Constraints:
#  
#  n == colors.length
#  m == edges.length
#  1 <= n <= 105
#  0 <= m <= 105
#  colors consists of lowercase English letters.
#  0 <= aj, bj < n
#  

from collections import defaultdict, deque
class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        n = len(colors)
        graph = defaultdict(list)
        indegree = defaultdict(int)
        for s, e in edges:
            graph[s].append(e)
            indegree[e] += 1

        q = deque()
        dp = [[0] * 26 for i in range(n)]
        res = 0
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)

        visited = 0
        while len(q) > 0:
            i = q.popleft()
            visited += 1
            k = ord(colors[i]) - ord('a')
            dp[i][k] += 1
            res = max(res, dp[i][k])

            for j in graph[i]:
                for c in range(26):
                    dp[j][c] = max(dp[j][c], dp[i][c])

                indegree[j] -= 1
                if indegree[j] == 0:
                    q.append(j)

        return res if visited == n else -1