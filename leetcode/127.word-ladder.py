class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        count = 0
        word_set = set(wordList)

        if endWord not in word_set:
            return 0

        queue = [beginWord]

        while(len(queue) > 0):
            
            size = len(queue)
            count += 1

            for _i in range(size):
                node  = queue.pop(0)
            
                if node == endWord:
                    return count

                neighbors = self.get_neighbors(node, word_set)
                for neighbor in neighbors:
                    queue.append(neighbor)

        return 0

    # using 26 letters is better than check every nodes in wordList
    # l = length of word
    # 26 letters = O(l * 25 * l)
    # each word has l * 25 variation, and to check or change each attempt using l
    #
    # check every nodes in wordlist = O(l * N * N)
    # to check neighbors of every word in the list needs l * N, and there are N such words
    def get_neighbors(self, word, word_set):
        results = []
        for i in range(len(word)):
            for letter in 'abcdefghijklmnopqrstuvwxyz':
                if letter == word[i]:
                    continue

                neighbor = word[:i] + letter + word[(i + 1):]
                if neighbor not in word_set:
                    continue
                    
                results.append(neighbor)
                word_set.remove(neighbor) #this is important

        return results