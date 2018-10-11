# Rabin-Karp
k_buckets = 131
k_characters = 256
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
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
            if tmp == target:
                match = True
                for j in range(n):
                    if haystack[i + j] != needle[j]:
                        match = False
                        break

                if match:
                    return i

            if i < m - n:
                tmp = (tmp - ord(haystack[i]) * high + ord(haystack[i + n])) % k_buckets
                if tmp < 0:
                    tmp += k_buckets

        return -1

class Solution2(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        m = len(haystack)
        n = len(needle)

        if n == 0:
            return 0

        if n > m:
            return -1

        for i in range(m - n + 1):
            for j in range(n):
                match = True
                if haystack[i + j] != needle[j]:
                    match = False
                    break

            if match:
                return i
        return -1
