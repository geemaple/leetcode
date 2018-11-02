class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        formatter = []
        letter = words[0]
        line = [letter]
        width = len(letter)
        
        for word in words[1:]:
            if width + 1 + len(word) > maxWidth:
                formatter.append((width, line))
                line = [word]
                width = len(word)
            else:
                line.append(word)
                width += 1 + len(word)
                
        formatter.append((width, line))

        return self.layouter(formatter, maxWidth)
                                
    def layouter(self, formatter, maxWidth):
        result = []
                                
        for i in range(len(formatter)):
            line = ""
            width = formatter[i][0]
            words = formatter[i][1]
                        
            # last line or single word line
            if i == len(formatter) - 1 or len(words) == 1:
                line = " ".join(words)
                line += " " * (maxWidth - width)
            else:
                avg = (maxWidth - width) // (len(words) - 1)
                extra = (maxWidth - width) % (len(words) - 1)
                line = words[0]
                for word in words[1:]:
                    line += " " * (avg + 1)
                    if extra > 0:
                        line += " "
                        extra -= 1
                    line += word
            result.append(line)
                                
        return result     