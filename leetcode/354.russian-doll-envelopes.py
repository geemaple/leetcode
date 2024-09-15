#  Tag: Array, Binary Search, Dynamic Programming, Sorting
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
#  One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
#  Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
#  Note: You cannot rotate an envelope.
#   
#  Example 1:
#  
#  Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
#  Output: 3
#  Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
#  
#  Example 2:
#  
#  Input: envelopes = [[1,1],[1,1],[1,1]]
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= envelopes.length <= 105
#  envelopes[i].length == 2
#  1 <= wi, hi <= 105
#  
#  

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        envelopes.sort(key=lambda x: (x[0], -x[1]))
        res = []
        for i in range(n):
            index = self.lower_bound(res, envelopes[i])
            if index == len(res):
                res.append(envelopes[i])
            else:
                res[index] = envelopes[i]

        return len(res)

    def lower_bound(self, ans: list, target: list) -> int:
        left = 0
        right = len(ans)

        while left < right:
            mid = (left + right) >> 1
            if target[1] > ans[mid][1]:
                left = mid + 1
            else:
                right = mid

        return left

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        envelopes.sort()
        dp = [1 for i in range(n)]
        for i in range(1, n):
            for j in range(i):
                if envelopes[i][0] != envelopes[j][0] and envelopes[i][1] > envelopes[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)

        return max(dp)