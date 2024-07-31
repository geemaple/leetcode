#  Tag: Array, Math, Divide and Conquer
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: dp

#  An array nums of length n is beautiful if:
#  
#  nums is a permutation of the integers in the range [1, n].
#  For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
#  
#  Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.
#   
#  Example 1:
#  Input: n = 4
#  Output: [2,1,4,3]
#  Example 2:
#  Input: n = 5
#  Output: [3,1,2,5,4]
#  
#   
#  Constraints:
#  
#  1 <= n <= 1000
#  
#  

from functools import lru_cache
class Solution:
    @lru_cache(maxsize=None)
    def beautifulArray(self, n: int) -> List[int]:

        if n == 1:
            return [1]

        even = self.beautifulArray(n // 2)
        odd = self.beautifulArray(n - (n // 2))

        res = []
        for k in even:
            res.append(2 * k)

        for k in odd:
            res.append(2 * k - 1)

        return res
    
class Solution:
    def beautifulArray(self, n: int) -> List[int]:

        dp = {1 : [1]}
        for i in range(2, n + 1):
            even = i // 2
            odd = i - even

            dp[i] = []
            for k in dp[even]:
                dp[i].append(2 * k)

            for k in dp[odd]:
                dp[i].append(2 * k - 1)

        return dp[n]
    
class Solution:
    def beautifulArray(self, n: int) -> List[int]:

        res = [1]
        while len(res) < n:
            even = [2 * i for i in res if 2 * i <= n]
            odd = [2 * i - 1 for i in res if 2 * i - 1 <= n]
            res = even + odd

        return res