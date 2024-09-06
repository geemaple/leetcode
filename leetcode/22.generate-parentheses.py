#  Tag: String, Dynamic Programming, Backtracking
#  Time: O(2^N)
#  Space: O(N)
#  Ref: -
#  Note: Catalan Number

#  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
#   
#  Example 1:
#  Input: n = 3
#  Output: ["((()))","(()())","(())()","()(())","()()()"]
#  Example 2:
#  Input: n = 1
#  Output: ["()"]
#  
#   
#  Constraints:
#  
#  1 <= n <= 8
#  
#  

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.helper(0, 0, n, "", res)
        return res

    def helper(self, left:int, right: int, n:int, ans: str, res:list):
        if left + right == n * 2:
            res.append(ans)
            return

        if left < n:
            self.helper(left + 1, right, n, ans + '(', res)

        if right < left:
            self.helper(left, right + 1,  n, ans + ')', res)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for i in range(n + 1)]
        dp[0] = [""]

        for i in range(1, n + 1):
            for j in range(i):
                left = dp[j]
                right = dp[i - j - 1]
                for l in left:
                    for r in right:
                        dp[i].append("(" + l + ")" + r)

        return dp[n]