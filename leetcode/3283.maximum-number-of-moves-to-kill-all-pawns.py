#  Tag: Array, Math, Bit Manipulation, Breadth-First Search, Game Theory, Bitmask
#  Time: O(2^K * K)
#  Space: O(2^K * K)
#  Ref: -
#  Note: -

#  There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.
#  Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:
#  
#  The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.
#  In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.
#  
#  Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.
#  Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.
#  Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
#  
#   
#  Example 1:
#  
#  Input: kx = 1, ky = 1, positions = [[0,0]]
#  Output: 4
#  Explanation:
#  
#  The knight takes 4 moves to reach the pawn at (0, 0).
#  
#  Example 2:
#  
#  Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]
#  Output: 8
#  Explanation:
#  
#  
#  Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
#  Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
#  Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).
#  
#  
#  Example 3:
#  
#  Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]
#  Output: 3
#  Explanation:
#  
#  Alice picks the pawn at (2, 4) and captures it in two moves: (0, 0) -> (1, 2) -> (2, 4). Note that the pawn at (1, 2) is not captured.
#  Bob picks the pawn at (1, 2) and captures it in one move: (2, 4) -> (1, 2).
#  
#  
#   
#  Constraints:
#  
#  0 <= kx, ky <= 49
#  1 <= positions.length <= 15
#  positions[i].length == 2
#  0 <= positions[i][0], positions[i][1] <= 49
#  All positions[i] are unique.
#  The input is generated such that positions[i] != [kx, ky] for all 0 <= i < positions.length.
#  
#  

from collections import deque, defaultdict
class Solution:
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:        
        n = 50
        positions =  positions + [[kx, ky]]
        k = len(positions)
        directions = [(-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (-1, -2), (1, -2)]
        dis = [[[-1] * n for j in range(n)] for i in range(k)]
        for i in range(k):
            x, y = positions[i]
            q = deque()
            q.append((x, y))
            dis[i][x][y] = 0
            while len(q) > 0:
                x, y = q.popleft()
                for d in range(8):
                    next_x = x + directions[d][0]
                    next_y = y + directions[d][1]
                    if 0 <= next_x < n and 0 <= next_y < n and dis[i][next_x][next_y] == -1:
                        dis[i][next_x][next_y] = dis[i][x][y] + 1
                        q.append((next_x, next_y))
        cache = defaultdict(dict)
        return self.helper(positions, 1 << (k - 1), k - 1, cache, dis)

    def helper(self, positions:list, mask: int, last: int, cache:dict, dis: list) -> int:
        n = len(positions)
        if mask == (1 << n) - 1:
            return 0

        if cache[mask].get(last, None) is None:
            count = bin(mask).count('1')
            res = float('-inf') if count & 1 else float('inf')
            
            for i in range(n):
                if not (mask >> i & 1):
                    x, y = positions[i]
                    step = self.helper(positions, mask | (1 << i), i, cache, dis) + dis[last][x][y]
                    if (count & 1):
                        res = max(res, step)
                    else:
                        res = min(res, step)

            cache[mask][last] = res
        return cache[mask][last]
    
class Solution:
    def maxMoves(self, kx: int, ky: int, positions: List[List[int]]) -> int:        
        n = 50
        positions =  positions + [[kx, ky]]
        k = len(positions)
        directions = [(-2, -1), (-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (-1, -2), (1, -2)]
        dis = [[[-1] * n for j in range(n)] for i in range(k)]
        for i in range(k):
            x, y = positions[i]
            q = deque()
            q.append((x, y))
            dis[i][x][y] = 0
            while len(q) > 0:
                x, y = q.popleft()
                for d in range(8):
                    next_x = x + directions[d][0]
                    next_y = y + directions[d][1]
                    if 0 <= next_x < n and 0 <= next_y < n and dis[i][next_x][next_y] == -1:
                        dis[i][next_x][next_y] = dis[i][x][y] + 1
                        q.append((next_x, next_y))

        dp = [[0] * k for i in range(1 << k)]
        for mask in range((1 << k) - 2, 0, -1):
            count = bin(mask).count('1')

            for i in range(k):
                dp[mask][i] = float('-inf') if count & 1 else float('inf')

            for i in range(k):
                if (mask >> i & 1):
                    for j in range(k):
                        if not (mask >> j & 1):
                            x, y = positions[j]
                            if (count & 1):
                                dp[mask][i] = max(dp[mask][i], dp[mask | 1 << j][j] + dis[i][x][y])
                            else:
                                dp[mask][i] = min(dp[mask][i], dp[mask | 1 << j][j] + dis[i][x][y])

        return dp[1 << (k - 1)][k - 1]