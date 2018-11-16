class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        self.helper('', 0, 0, n, res)
        return res
        
    def helper(self, ans, left, right, limit, res):
        if left + right == limit * 2:
            res.append(ans)
            return
        
        if left < limit:
            self.helper(ans + '(', left + 1, right, limit, res)
            
        if right < left:
            self.helper(ans + ')', left, right + 1, limit, res)