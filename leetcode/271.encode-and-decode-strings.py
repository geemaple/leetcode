class Codec:

    def encode(self, strs):
        """Encodes a list of strings to a single string.
        
        :type strs: List[str]
        :rtype: str
        """
        res = ""

        for i in range(len(strs)):
            for j in range(len(strs[i])):
                if strs[i][j] == '|':
                    res += '||'
                else:
                    res += strs[i][j]
            res += '|+'

        return res
        

    def decode(self, s):
        """Decodes a single string to a list of strings.
        
        :type s: str
        :rtype: List[str]
        """
        res = []
        word = ''
        i = 0

        while (i < len(s)):
            if s[i] == '|':
                if s[i + 1] == '+':
                    res.append(word)
                    word = ''
                else:
                    word += s[i + 1]
                i += 1
            else:
                word += s[i]
            i += 1

        return res

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))