#  Tag: Backtracking
#  Time: O(k * C(n, k))
#  Space: O(K)
#  Ref: -
#  Note: -

#  Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#  You may return the answer in any order.
#   
#  Example 1:
#  
#  Input: n = 4, k = 2
#  Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
#  Explanation: There are 4 choose 2 = 6 total combinations.
#  Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
#  
#  Example 2:
#  
#  Input: n = 1, k = 1
#  Output: [[1]]
#  Explanation: There is 1 choose 1 = 1 total combination.
#  
#   
#  Constraints:
#  
#  1 <= n <= 20
#  1 <= k <= n
#  
#  

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []
        tmp = []
        self.dfs(n, k, 1, tmp, res)

        return res


    def dfs(self, n: int, k:int, start: int, tmp: list, ans: List[List[int]]):
        if len(tmp) == k:
            ans.append(tmp.copy())
            return

        for i in range(start, n + 1):
            tmp.append(i)
            self.dfs(n, k, i + 1, tmp, ans)
            tmp.pop()