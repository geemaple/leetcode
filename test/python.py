class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)

        if (m > n):
            return -1

        k_ascii = 256
        k_buckets = 131

        high_k = 1
        for i in range(m - 1): # 最高位 = k ^ (m - 1)
            high_k = (high_k * k_ascii) % k_buckets

        needle_hash = 0
        test_hash = 0
        for i in range(m):
            needle_hash = (needle_hash * k_ascii + ord(needle[i])) % k_buckets
            test_hash = (test_hash * k_ascii + ord(haystack[i])) % k_buckets

        for i in range(n - m + 1):
            if test_hash == needle_hash:
                found = True
                for j in range(m):
                    if haystack[i + j] != needle[j]:
                        found = False
                        break

                if found:
                    return i

            if i + m < n:
                test_hash = ((test_hash - ord(haystack[i]) * high_k) * k_ascii + ord(haystack[i + m])) % k_buckets

        return -1
    
s = Solution()
res = s.strStr("adcadcaddcadde", "adcadde")
print(res)