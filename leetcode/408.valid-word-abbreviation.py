class Solution(object):
    def validWordAbbreviation(self, word, abbr):
        """
        :type word: str
        :type abbr: str
        :rtype: bool
        """
        left = 0
        right = 0
        numbers = set(list("0123456789"))

        while(left < len(word) and right < len(abbr)):

            if abbr[right] == '0':
                return False

            elif abbr[right] in numbers:
                step = int(abbr[right])
                while(right + 1 < len(abbr) and abbr[right + 1] in numbers):
                    step =  step * 10 + int(abbr[right + 1])
                    right += 1
                    
                right += 1
                left += step
                continue

            elif word[left] != abbr[right]:
                return False

            left += 1
            right += 1

        return (left == len(word) and right == len(abbr))
