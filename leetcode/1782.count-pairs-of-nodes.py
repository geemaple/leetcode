#  Tag: Array, Two Pointers, Binary Search, Graph, Sorting
#  Time: O(VlogV + E)
#  Space: O(V + E)
#  Ref: -
#  Note: -

#  You are given an undirected graph defined by an integer n, the number of nodes, and a 2D integer array edges, the edges in the graph, where edges[i] = [ui, vi] indicates that there is an undirected edge between ui and vi. You are also given an integer array queries.
#  Let incident(a, b) be defined as the number of edges that are connected to either node a or b.
#  The answer to the jth query is the number of pairs of nodes (a, b) that satisfy both of the following conditions:
#  
#  a < b
#  incident(a, b) > queries[j]
#  
#  Return an array answers such that answers.length == queries.length and answers[j] is the answer of the jth query.
#  Note that there can be multiple edges between the same two nodes.
#   
#  Example 1:
#  
#  
#  Input: n = 4, edges = [[1,2],[2,4],[1,3],[2,3],[2,1]], queries = [2,3]
#  Output: [6,5]
#  Explanation: The calculations for incident(a, b) are shown in the table above.
#  The answers for each of the queries are as follows:
#  - answers[0] = 6. All the pairs have an incident(a, b) value greater than 2.
#  - answers[1] = 5. All the pairs except (3, 4) have an incident(a, b) value greater than 3.
#  
#  Example 2:
#  
#  Input: n = 5, edges = [[1,5],[1,5],[3,4],[2,5],[1,3],[5,1],[2,3],[2,5]], queries = [1,2,3,4,5]
#  Output: [10,10,9,8,6]
#  
#   
#  Constraints:
#  
#  2 <= n <= 2 * 104
#  1 <= edges.length <= 105
#  1 <= ui, vi <= n
#  ui != vi
#  1 <= queries.length <= 20
#  0 <= queries[j] < edges.length
#  
#  

from collections import defaultdict
class Solution:
    def countPairs(self, n: int, edges: List[List[int]], queries: List[int]) -> List[int]:
        degrees = [0 for i in range(n + 1)]
        counter = defaultdict(int)
        for x, y in edges:
            degrees[x] += 1
            degrees[y] += 1
            key = (x, y) if x < y else (y, x)
            counter[key] += 1

        sorted_degrees = sorted(degrees)
        res = []
        for k in queries:
            res.append(self.count(degrees, sorted_degrees, counter, k))
        return res
        
    def count(self, degrees: list, sorted_degrees: list, counter: dict, target: int) -> int:
        n = len(degrees)
        res = 0
        j = n - 1
        for i in range(1, n):
            while j > i and sorted_degrees[i] + sorted_degrees[j] > target:
                j -= 1
            res += n - max(i, j) - 1

        count = 0
        for x, y in counter:
            if degrees[x] + degrees[y] > target and degrees[x] + degrees[y] - counter[(x, y)] <= target:
                count += 1

        return res - count