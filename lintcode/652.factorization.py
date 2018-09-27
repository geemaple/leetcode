class Solution:
    """
    @param n: An integer
    @return: a list of combination
    """
    def getFactors(self, n):
        # write your code here
        res = []
        ans = []
        self.dfs(2, n, ans, res)
        return res


    def dfs(self, start, remain, ans, res):
        
        if len(ans) > 0:
            ans.append(remain)
            res.append(ans[:])
            ans.pop()

        for i in range(start, remain):
            if remain / i < i:
                break

            if remain % i == 0:
                ans.append(i)
                self.dfs(i, remain // i, ans, res)
                ans.pop()