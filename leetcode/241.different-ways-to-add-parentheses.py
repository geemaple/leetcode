#  Tag: Math, String, Dynamic Programming, Recursion, Memoization
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
#  The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
#   
#  Example 1:
#  
#  Input: expression = "2-1-1"
#  Output: [0,2]
#  Explanation:
#  ((2-1)-1) = 0 
#  (2-(1-1)) = 2
#  
#  Example 2:
#  
#  Input: expression = "2*3-4*5"
#  Output: [-34,-14,-10,-10,10]
#  Explanation:
#  (2*(3-(4*5))) = -34 
#  ((2*3)-(4*5)) = -14 
#  ((2*(3-4))*5) = -10 
#  (2*((3-4)*5)) = -10 
#  (((2*3)-4)*5) = 10
#  
#   
#  Constraints:
#  
#  1 <= expression.length <= 20
#  expression consists of digits and the operator '+', '-', and '*'.
#  All the integer values in the input expression are in the range [0, 99].
#  
#  

from functools import lru_cache
class Solution:
    @lru_cache(maxsize=None)
    def diffWaysToCompute(self, expression: str) -> List[int]:
        
        res = []
        for i in range(len(expression)):
            op = expression[i]
            if op in ['+', '-', '*']:
                left = self.diffWaysToCompute(expression[:i])
                right = self.diffWaysToCompute(expression[i + 1:])

                for l in left:
                    for r in right:
                        if op == '+':
                            res.append(l + r)
                        elif op == '-':
                            res.append(l - r)
                        else:
                            res.append(l * r)

        if len(res) == 0:
            res.append(int(expression))

        return res
    
class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        n = len(expression)
        nums = []
        ops = []

        i = 0
        for j in range(n):
            op = expression[j]
            if op in ['+', '-', '*']:
                ops.append(op)
                nums.append(expression[i:j])
                i = j + 1
        nums.append(expression[i: n])

        return self.solve(nums, ops)

    def solve(self, nums: list, ops: list) -> List[int]:
        n = len(nums)
        dp = [[[] for i in range(n)] for i in range(n)]

        for i in range(n):
            for j in range(i, -1, -1):
                if i == j:
                    dp[i][i].append(int(nums[i]))
                else:
                    for k in range(j, i):
                        for l in dp[j][k]:
                            for r in dp[k + 1][i]:
                                if ops[k] == '+':
                                    dp[j][i].append(l + r)
                                elif ops[k] == '-':
                                    dp[j][i].append(l - r)
                                else:
                                    dp[j][i].append(l * r)
        return dp[0][n - 1]