
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def maximumSubarrayXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        res = []
        for query in queries:
            res.append(self.query(nums, query))
        return res


    def query(self, nums: list, query: list) -> int:
        i, j = query
        n = j - i + 1
        dp = nums[i : j + 1]
        res = max(dp)
  
        for t in range(n - 1):
            for k in range(n - t - 1):
                dp[k] = dp[k] ^ dp[k + 1]
                res = max(res, dp[k])
                print(dp)
        print(res, dp)
        return res

s = Solution()
board = [2,8,4,32,16,1]
res = s.maximumSubarrayXor(board, [[0,2],[1,4],[0,5]])
print(res)