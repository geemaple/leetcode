class Solution(object):
    def findLadders(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: List[List[str]]
        """

        distant_map = {}
        for word in wordList:
            distant_map[word] = 0

        if endWord not in distant_map:
            return []

        # using BFS to get each word distancd to endWord
        self.bfs_traversal(endWord, distant_map)

        results = []
        tmp = [beginWord]
        visted = set()
        self.dfs_traversal(beginWord, endWord, tmp, results, visted, distant_map)
        return results

    def dfs_traversal(self, word, endWord, tmp, results, visted, distant_map):
        if word == endWord:
            results.append(list(tmp))
            return

        distance = distant_map.get(word, float('inf'))
        neighbors = self.get_neighbors(word, visted, distant_map)
    
        for neighbor in neighbors:
            if distant_map[neighbor] >= distance:
                continue

            visted.add(neighbor)

            tmp.append(neighbor)
            self.dfs_traversal(neighbor, endWord, tmp, results, visted, distant_map)
            tmp.pop()

            visted.remove(neighbor)

        
    def bfs_traversal(self, endWord, distant_map):

        visted = set()
        queue = [endWord]
        visted.add(endWord)
        count = 0

        while(len(queue) > 0):
            
            size = len(queue)

            for _ in range(size):
                word = queue.pop(0)

                distant_map[word] = count

                neighbors = self.get_neighbors(word, visted, distant_map)
                for neighbor in neighbors:
                    queue.append(neighbor)
                    visted.add(neighbor)
            
            count += 1


    def get_neighbors(self, word, visted, distant_map):
        
        results = []

        for i in range(len(word)):
            for letter in 'abcdefghijklmnopqrstuvwxyz':
                if letter == word[i]:
                    continue

                neighbor = word[:i] + letter + word[(i + 1):]

                if neighbor not in distant_map:
                    continue

                if neighbor in visted:
                    continue

                results.append(neighbor)

        return results