class Solution(object):
    def __init__(self, *args, **kwargs):
        self.mapping = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']
        }

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if digits is None or len(digits) == 0:
            return []

        res = []
        self.dfs(0, digits, "", res)
        return res
        

    def dfs(self, level, digits, ans, res):
        if level == len(digits):
            res.append(ans)
            return

        number = digits[level]
        size = len(self.mapping[number])
        for i in range(size):
            ans += self.mapping[number][i]
            self.dfs(level + 1, digits, ans, res)
            ans = ans[:-1]
        
