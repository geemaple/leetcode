class Solution(object):
    def __init__(self):
        self.is_palindrome = None

    def pre_build(self, s):

        size = len(s)
        self.is_palindrome = [[False for _ in range(size)] for _ in range(size)]

        for t in range(size):
            i = j = t
            while i >= 0 and j < size and s[i] == s[j]:
                self.is_palindrome[i][j] = True
                i -= 1
                j += 1

            i = t
            j = t + 1
            while i >= 0 and j < size and s[i] == s[j]:
                self.is_palindrome[i][j] = True
                i -= 1
                j += 1

    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """

        self.pre_build(s)
        results = []
        ans = []
        self.helper(s, 0, ans, results)
        return results

    def helper(self, s, start, ans, results):
        
        if start == len(s):
            results.append(list(ans))

        for i in range(start, len(s)):
    
            if not self.is_palindrome[start][i]:
                continue

            ans.append(s[start: i + 1])
            self.helper(s, i + 1, ans, results)
            ans.pop()