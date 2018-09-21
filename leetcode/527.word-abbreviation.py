class Solution(object):
    def wordsAbbreviation(self, dict):
        """
        :type dict: List[str]
        :rtype: List[str]
        """
        res = []
        countMap = {}
        prefix = [1] * len(dict)

        for word in dict:
            abbr = self.abbreviateWord(word, 1)
            res.append(abbr)
            countMap[abbr] = countMap.get(abbr, 0) + 1

        while(True):
            unique = True

            for i in range(len(res)):
                if countMap.get(res[i], 0) > 1:
                    unique = False
                    prefix[i] += 1
                    abbr = self.abbreviateWord(dict[i], prefix[i])
                    res[i] = abbr
                    countMap[abbr] = countMap.get(abbr, 0) + 1

            if unique:
                break

        return res
        
    def abbreviateWord(self, word, pos):
        if pos + 2 >= len(word):
            return word

        return word[:pos] + str(len(word) - pos - 1) + word[-1]