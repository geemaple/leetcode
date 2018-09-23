class ValidWordAbbr(object):

    def __init__(self, dictionary):
        """
        :type dictionary: List[str]
        """

        self.word_map = {}

        for word in dictionary:
            abbr = self.abbreviate(word)
            if abbr in self.word_map:
                self.word_map[abbr].add(word)
            else:
                self.word_map[abbr] = set([word])
        

    def isUnique(self, word):
        """
        :type word: str
        :rtype: bool
        """
        abbr = self.abbreviate(word)
        return abbr not in self.word_map or (len(self.word_map[abbr]) == 1 and word in self.word_map[abbr])
        
    def abbreviate(self, word):
        if len(word) < 3:
            return word
        else:
            return word[0] + str(len(word) - 2) + word[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param_1 = obj.isUnique(word)
