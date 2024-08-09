#  Tag: Two Pointers, String, String Matching
#  Time: O(M + N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#   
#  Example 1:
#  
#  Input: haystack = "sadbutsad", needle = "sad"
#  Output: 0
#  Explanation: "sad" occurs at index 0 and 6.
#  The first occurrence is at index 0, so we return 0.
#  
#  Example 2:
#  
#  Input: haystack = "leetcode", needle = "leeto"
#  Output: -1
#  Explanation: "leeto" did not occur in "leetcode", so we return -1.
#  
#   
#  Constraints:
#  
#  1 <= haystack.length, needle.length <= 104
#  haystack and needle consist of only lowercase English characters.
#  
#  

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)

        for i in range(n):
            if haystack[i : i + m] == needle:
                return i

        return -1

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        dp = self.buildNext(needle)
        match_length = 0

        for i in range(n):
            while match_length > 0 and haystack[i] != needle[match_length]:
                match_length = dp[match_length - 1]

            if haystack[i] == needle[match_length]:
                match_length += 1

            if match_length == m:
                return i - m + 1

        return -1

    def buildNext(self, text: str) -> list[int]:
        n = len(text)
        dp = [0] * n
        k = 0
        for i in range(1, n):
            while k > 0 and text[i] != text[k]:
                k = dp[k - 1]

            if text[i] == text[k]:
                k += 1

            dp[i] = k
        
        return dp
    
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