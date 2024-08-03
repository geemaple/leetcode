#  Tag: Depth-First Search, Graph, Eulerian Circuit
#  Time: O(ElogE)
#  Space: O(E+V)
#  Ref: -
#  Note: Containers

#  You are given a list of airline tickets where tickets[i] = [fromi, toi] represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.
#  All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.
#  
#  For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
#  
#  You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.
#   
#  Example 1:
#  
#  
#  Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
#  Output: ["JFK","MUC","LHR","SFO","SJC"]
#  
#  Example 2:
#  
#  
#  Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
#  Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
#  Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.
#  
#   
#  Constraints:
#  
#  1 <= tickets.length <= 300
#  tickets[i].length == 2
#  fromi.length == 3
#  toi.length == 3
#  fromi and toi consist of uppercase English letters.
#  fromi != toi
#  
#  

from collections import defaultdict, deque
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets.sort()
        graph = defaultdict(deque)
        for start, to in tickets:
            graph[start].append(to)

        res = []
        self.dfs("JFK", graph, res)
        return res[::-1]

    def dfs(self, start, graph, res):
        q = graph[start]
        while len(q) > 0:
            to = q.popleft()
            self.dfs(to, graph, res)

        res.append(start)

from collections import defaultdict
import heapq
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for start, to in tickets:
            heapq.heappush(graph[start], to)

        res = []
        self.dfs("JFK", graph, res)
        return res[::-1]

    def dfs(self, start, graph, res):
        while len(graph[start]) > 0:
            to = heapq.heappop(graph[start])
            self.dfs(to, graph, res)

        res.append(start)

from collections import defaultdict
import heapq
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = defaultdict(list)
        for start, to in tickets:
            heapq.heappush(graph[start], to)

        res = []
        stack = ["JFK"]
        while len(stack) > 0:
            cur = stack[-1]
            if (len(graph[cur]) > 0):
                to = heapq.heappop(graph[cur])
                stack.append(to)
            else:
                res.append(cur)
                stack.pop()

        return res[::-1]