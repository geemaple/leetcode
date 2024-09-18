#  Tag: Math, Dynamic Programming, Breadth-First Search
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer n, return the least number of perfect square numbers that sum to n.
#  A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
#   
#  Example 1:
#  
#  Input: n = 12
#  Output: 3
#  Explanation: 12 = 4 + 4 + 4.
#  
#  Example 2:
#  
#  Input: n = 13
#  Output: 2
#  Explanation: 13 = 4 + 9.
#  
#   
#  Constraints:
#  
#  1 <= n <= 104
#  
#  

from collections import deque
class Solution:
    def numSquares(self, n: int) -> int:
        squares = [i * i for i in range(1, int(n ** 0.5) + 1)]
        q = deque([n])

        level = 0
        while len(q) > 0:
            size = len(q)
            level += 1

            for i in range(size):
                cur = q.popleft()
                for square in squares:
                    next_val = cur - square
                    if next_val == 0:
                        return level
                    if next_val > 0:
                        q.append(next_val)

        return level

class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n + 1)]

        for i in range(1, n + 1):
            j = 1
            while (j * j <= i):
                dp[i] = min(dp[i], dp[i - j * j] + 1)
                j += 1

        return dp[n]
