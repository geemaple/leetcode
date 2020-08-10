# Rabin-Karp
k_buckets = 131
k_characters = 256
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        
        m = len(haystack)
        n = len(needle)

        if n == 0:
            return 0

        if n > m:
            return -1

        target = 0
        tmp = 0
        high = 1

        for i in range(n - 1):
            high = (high * k_characters) % k_buckets

        for i in range(n):
            tmp = (tmp * k_characters + ord(haystack[i])) % k_buckets
            target = (target * k_characters + ord(needle[i])) % k_buckets

        for i in range(m - n + 1):
            index = i
            if tmp == target:
                for j in range(n):
                    if haystack[i + j] != needle[j]:
                        index = -1
                        break

                if index == i:
                    return index

            if i < m - n:
                tmp = ((tmp - ord(haystack[i]) * high) * k_characters  + ord(haystack[i + n])) % k_buckets

        return -1

class Solution2:
    def strStr(self, haystack: str, needle: str) -> int:
        
        if len(needle) > len(haystack):
            return -1
        
        index = 0
        for i in range(len(haystack) - len(needle) + 1):
            index = i
            for j in range(len(needle)):
                if needle[j] != haystack[i + j]:
                    index = -1
                    break
            
            if index == i:
                break
            
        return index
