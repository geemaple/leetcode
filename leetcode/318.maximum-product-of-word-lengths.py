class Solution(object):
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        if words is None or len(words) == 0:
            return 0
        
        mask = [0 for _ in range(len(words))]
        
        for i in range(len(words)):
            for c in words[i]:
                mask[i] |= 1 << (ord(c) - ord('a'))
                
        res = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if (mask[i] & mask[j] == 0 and len(words[i]) * len(words[j]) > res):
                    res = len(words[i]) * len(words[j])
                    
        return res