#  Tag: Hash Table
#  Time: O(1)
#  Space: O(N)
#  Ref: Leetcode-288
#  Note: -

#  An abbreviation of a word follows the form ```<first letter><number><last letter>```, the number indicates the length of the abbreviated part.
#  Below are some examples of word abbreviations:
#  ```
#  a) it                      --> it    (no abbreviation)
#  
#       1
#  b) d|o|g                   --> d1g
#  
#                1    1  1
#       1---5----0----5--8
#  c) i|nternationalizatio|n  --> i18n
#  
#                1
#       1---5----0
#  d) l|ocalizatio|n          --> l10n
#  ```
#  Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
#  A word's abbreviation is unique if **no other word** from the dictionary has the same abbreviation.
#  
#  **Example1**
#  ```
#  Input:
#  [ "deer", "door", "cake", "card" ]
#  isUnique("dear")
#  isUnique("cart")
#  Output:
#  false
#  true
#  Explanation:
#  Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
#  "dear" 's abbreviation is "d2r" , in dictionary.
#  "cart" 's abbreviation is "c2t" , not in dictionary.
#  ```
#  **Example2**
#  ```
#  Input:
#  [ "deer", "door", "cake", "card" ]
#  isUnique("cane")
#  isUnique("make")
#  Output:
#  false
#  true
#  Explanation:
#  Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
#  "cane" 's abbreviation is "c2e" , in dictionary.
#  "make" 's abbreviation is "m2e" , not in dictionary.
#  ```
#  
#  

from collections import defaultdict
class ValidWordAbbr:
    """
    @param: dictionary: a list of words
    """
    def __init__(self, dictionary):
        # do intialization if necessary
        self.word_map = defaultdict(set)
        for x in dictionary:
            ab = self.abbreviate(x)
            self.word_map[ab].add(x)

    """
    @param: word: a string
    @return: true if its abbreviation is unique or false
    """
    def isUnique(self, word):
        # write your code here
        ab = self.abbreviate(word)
        return ab not in self.word_map or (len(self.word_map[ab]) == 1 and word in self.word_map[ab])

    def abbreviate(self, word) -> str:
        if len(word) <= 2:
            return word
        else:
            return word[0] + str(len(word) - 2) + word[-1]


# Your ValidWordAbbr object will be instantiated and called as such:
# obj = ValidWordAbbr(dictionary)
# param = obj.isUnique(word)