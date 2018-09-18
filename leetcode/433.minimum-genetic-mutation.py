CHOICES = ["A", "C", "G", "T"]
class Solution(object):
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        queue = [start]
        level = 0
        bank_set = set(bank)
        visited = set([start])
        
        while(len(queue) > 0):
            size = len(queue)
            for _ in range(size):
                top = queue.pop(0)
                if top == end:
                    return level
                
                for neighbor in self.find_neighbors(top, bank_set):
                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append(neighbor)

            level += 1
        return -1

    def find_neighbors(self, gene, bank):
        neighbors = []
        for i in range(len(gene)):
            origin = gene[i]
            for mutated in CHOICES:
                if mutated == origin:
                    continue
                new_gene = gene[:i] + mutated + gene[i + 1:] 
                if new_gene not in bank:
                    continue

                neighbors.append(new_gene)

        return neighbors