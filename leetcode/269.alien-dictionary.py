from collections import deque
class Solution(object):

    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        letters = set()
        indegree = {}
        graph = {}

        for word in words:
            for l in word:
                letters.add(l)
        
        for i in range(1, len(words)):
            pre = words[i - 1]
            cur = words[i]
            
            length = min(len(pre), len(cur))

            for j in range(length):
                node = pre[j]
                neighbor = cur[j]

                if node == neighbor:
                    continue

                if neighbor not in graph.get(node, set()):
                    # graph
                    if node in graph:
                        graph[node].add(neighbor)
                    else:
                        graph[node] = set([neighbor])
                        
                    # indegree
                    indegree[neighbor] = indegree.get(neighbor, 0) + 1

                break
                        
        q = deque()
        for l in letters:
            if indegree.get(l, 0) == 0:
                q.append(l)
        
        res = ''
        while len(q) > 0:
            tmp = q.popleft()
            res += tmp
            
            for neighbor in graph.get(tmp, set()):
                if neighbor not in indegree:
                    continue

                indegree[neighbor] -= 1
                if indegree[neighbor] == 0:
                    del indegree[neighbor]
                    q.append(neighbor)
        
        return res if len(indegree) == 0 else ''