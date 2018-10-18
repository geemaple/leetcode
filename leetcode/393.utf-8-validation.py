class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        if data is None or len(data) == 0:
            return False
        
        i = 0
        while i < len(data):
            n = self.byteLength(data[i])
            if n == 0 or n + i - 1 >= len(data):
                return False
            
            for j in range(i + 1, n + i):
                if (data[j] >> 6) != 0b10:
                    return False
            
            i = i + n
            
        return True
        
    def byteLength(self, n):
        if (n >> 7) == 0b0:
            return 1
        if (n >> 5) == 0b110:
            return 2
        if (n >> 4) == 0b1110:
            return 3
        if (n >> 3) == 0b11110:
            return 4
        return 0