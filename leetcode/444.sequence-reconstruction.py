import collections
class Solution(object):
    def sequenceReconstruction(self, org, seqs):
        """
        :type org: List[int]
        :type seqs: List[List[int]]
        :rtype: bool
        """
        
        graph = collections.defaultdict(list)
        indegree_map = {}

        # build graph and count indegree
        for pair in seqs:
            if len(pair) == 0:
                continue

            for i in range(len(pair)):
                node = pair[i]
                _ = graph[node]

                if i + 1 >= len(pair):
                    continue

                neighbor = pair[i + 1]
                _ = graph[neighbor]
                graph[node].append(neighbor)

                if neighbor in indegree_map:
                    indegree_map[neighbor] = indegree_map[neighbor] + 1
                else:
                    indegree_map[neighbor] = 1

        # find node with in degree = 0
        queue = []
        for node in graph:
            if node not in indegree_map:
                queue.append(node)

        # get topological sort with bfs
        result = []
        while(len(queue) > 0):
            if len(queue) > 1:
                return False
            
            # if non-recursive dfs, using queue.pop()
            # reference: https://stackoverflow.com/a/5278667/1389917
            node = queue.pop(0) 
            result.append(node)

            for neighbor in graph[node]:
                if neighbor in indegree_map:
                    indegree_map[neighbor] = indegree_map[neighbor] - 1
                    if indegree_map[neighbor] == 0:
                        queue.append(neighbor)
                        del indegree_map[neighbor]

        if len(indegree_map) > 0:
            return False

        if len(result) != len(org):
            return False

        for i in range(len(result)):
            if result[i] != org[i]:
                return False

        return True