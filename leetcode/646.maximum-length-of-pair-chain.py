#  Tag: Array, Dynamic Programming, Greedy, Sorting
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an array of n pairs pairs where pairs[i] = [lefti, righti] and lefti < righti.
#  A pair p2 = [c, d] follows a pair p1 = [a, b] if b < c. A chain of pairs can be formed in this fashion.
#  Return the length longest chain which can be formed.
#  You do not need to use up all the given intervals. You can select pairs in any order.
#   
#  Example 1:
#  
#  Input: pairs = [[1,2],[2,3],[3,4]]
#  Output: 2
#  Explanation: The longest chain is [1,2] -> [3,4].
#  
#  Example 2:
#  
#  Input: pairs = [[1,2],[7,8],[4,5]]
#  Output: 3
#  Explanation: The longest chain is [1,2] -> [4,5] -> [7,8].
#  
#   
#  Constraints:
#  
#  n == pairs.length
#  1 <= n <= 1000
#  -1000 <= lefti < righti <= 1000
#  
#  

class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        n = len(pairs)
        pairs.sort()
        
        dp = [1 for i in range(n)]

        for i in range(1, n):
            for j in range(i):
                if pairs[j][1] < pairs[i][0]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)
    
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        
        pairs.sort()
        dp = []

        for pair in pairs:
            i = self.lower_bound(dp, pair[0])
            if i == len(dp):
                dp.append(pair)
            else:
                if dp[i][1] > pair[1]:
                    dp[i] = pair

        return len(dp)

    def lower_bound(self, dp: list, val: int) -> int:
        left, right = 0, len(dp)
        while left < right:
            mid = (left + right) // 2
            if dp[mid][1] < val:
                left = mid + 1
            else:
                right = mid
        return left
    
class Solution:
    def findLongestChain(self, pairs):
        n = len(pairs)
        pairs.sort(key = lambda x: x[1])
        ans = 1
        cur = pairs[0][1]

        for i in range(1, n):
            if pairs[i][0] > cur:
                ans += 1
                cur = pairs[i][1]

        return ans