#  Tag: Array, Dynamic Programming, Matrix
#  Time: O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/Y2FlnwK0ADQ

#  There is a game dungeon comprised of n x n rooms arranged in a grid.
#  You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
#  The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
#  
#  The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
#  The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
#  The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
#  
#  When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
#  Return the maximum number of fruits the children can collect from the dungeon.
#   
#  Example 1:
#  
#  Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
#  Output: 100
#  Explanation:
#  
#  In this example:
#  
#  The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
#  The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
#  The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
#  
#  In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.
#  
#  Example 2:
#  
#  Input: fruits = [[1,1],[1,1]]
#  Output: 4
#  Explanation:
#  In this example:
#  
#  The 1st child moves on the path (0,0) -> (1,1).
#  The 2nd child moves on the path (0,1) -> (1,1).
#  The 3rd child moves on the path (1,0) -> (1,1).
#  
#  In total they collect 1 + 1 + 1 + 1 = 4 fruits.
#  
#   
#  Constraints:
#  
#  2 <= n == fruits.length == fruits[i].length <= 1000
#  0 <= fruits[i][j] <= 1000
#  
#  
class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        for i in range(n):
            for j in range(n):
                if i < j and j < n - 1 - i:
                    fruits[i][j] = 0

                if j < i and i < n - 1 - j:
                    fruits[i][j] = 0

        child1 = 0
        for i in range(n):
            child1 += fruits[i][i]

        for i in range(1, n):
            for j in range(i + 1, n):
                if j + 1 < n:
                    fruits[i][j] += max(fruits[i - 1][j], fruits[i - 1][j - 1], fruits[i - 1][j + 1])
                else:
                    fruits[i][j] += max(fruits[i - 1][j], fruits[i - 1][j - 1])
        child2 = fruits[n - 2][n - 1]

        for j in range(1, n):
            for i in range(j + 1, n):
                if i + 1 < n:
                    fruits[i][j] += max(fruits[i][j - 1], fruits[i - 1][j - 1], fruits[i + 1][j - 1])
                else:
                    fruits[i][j] += max(fruits[i][j - 1], fruits[i - 1][j - 1])

        child3 = fruits[n - 1][n - 2]

        return child1 + child2 + child3

class Solution:
    def maxCollectedFruits(self, fruits: List[List[int]]) -> int:
        n = len(fruits)
        child1 = 0
        for i in range(n):
            child1 += fruits[i][i]
            fruits[i][i] = 0
        
        dp = [[0] * n for i in range(n)]
        dp[0][n - 1] = fruits[0][n - 1]
        for i in range(1, n):
            for j in range(n - i - 1, n):
                if j == 0:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j]
                elif j == n - 1:
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + fruits[i][j]
                else:
                    dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j]

        child2 = dp[n - 1][n - 1]
        j = n - 1
        for i in range(n - 1, 0, -1):
            val = fruits[i][j]
            fruits[i][j] = 0
            if j > 0 and dp[i - 1][j - 1] + val == dp[i][j]:
                j = j - 1
            elif j < n - 1 and dp[i - 1][j + 1] + val == dp[i][j]:
                j = j + 1

        dp = [[0] * n for i in range(n)]
        dp[n - 1][0] = fruits[n - 1][0]
        for j in range(1, n):
            for i in range(n - j - 1, n):
                if i == 0:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j - 1]) + fruits[i][j]
                elif i == n - 1:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]) + fruits[i][j]
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]) + fruits[i][j]

        child3 = dp[n - 1][n - 1]
        return child1 + child2 + child3