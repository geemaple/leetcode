from typing import List
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
s = Solution()
res = s.diffWaysToCompute("2-1-1")
print(res)