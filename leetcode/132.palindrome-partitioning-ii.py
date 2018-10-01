# f(i) = min(f[j] + 1 where 0 <= j <= i - 1 and s[j: i - 1] is palindrome)
class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        if s is None or len(s) == 0:
            return 0

        m = len(s)
        store = [[False for _ in range(m)] for _ in range(m)]

        i = 0
        j = 0
        for t in range(m):
            i = j = t # odd palindrome
            while(i >= 0 and j < m and s[i] == s[j]):
                store[i][j] = True
                i -= 1
                j += 1

            i = t
            j = t + 1 # even palindrome
            while(i >= 0 and j < m and s[i] == s[j]):
                store[i][j] = True
                i -= 1
                j += 1

        table = [0 for _ in range(m + 1)]
        for i in range(1, m + 1):
            value = float('inf')
            for j in range(i):
                if store[j][i - 1]:
                    value = min(value, table[j] + 1)

            table[i] = value

        return table[-1] - 1