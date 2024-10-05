//  Tag: Array, Math, Bit Manipulation, Breadth-First Search, Game Theory, Bitmask
//  Time: O(2^K * K)
//  Space: O(2^K * K)
//  Ref: -
//  Note: -

//  There is a 50 x 50 chessboard with one knight and some pawns on it. You are given two integers kx and ky where (kx, ky) denotes the position of the knight, and a 2D array positions where positions[i] = [xi, yi] denotes the position of the pawns on the chessboard.
//  Alice and Bob play a turn-based game, where Alice goes first. In each player's turn:
//  
//  The player selects a pawn that still exists on the board and captures it with the knight in the fewest possible moves. Note that the player can select any pawn, it might not be one that can be captured in the least number of moves.
//  In the process of capturing the selected pawn, the knight may pass other pawns without capturing them. Only the selected pawn can be captured in this turn.
//  
//  Alice is trying to maximize the sum of the number of moves made by both players until there are no more pawns on the board, whereas Bob tries to minimize them.
//  Return the maximum total number of moves made during the game that Alice can achieve, assuming both players play optimally.
//  Note that in one move, a chess knight has eight possible positions it can move to, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.
//  
//   
//  Example 1:
//  
//  Input: kx = 1, ky = 1, positions = [[0,0]]
//  Output: 4
//  Explanation:
//  
//  The knight takes 4 moves to reach the pawn at (0, 0).
//  
//  Example 2:
//  
//  Input: kx = 0, ky = 2, positions = [[1,1],[2,2],[3,3]]
//  Output: 8
//  Explanation:
//  
//  
//  Alice picks the pawn at (2, 2) and captures it in two moves: (0, 2) -> (1, 4) -> (2, 2).
//  Bob picks the pawn at (3, 3) and captures it in two moves: (2, 2) -> (4, 1) -> (3, 3).
//  Alice picks the pawn at (1, 1) and captures it in four moves: (3, 3) -> (4, 1) -> (2, 2) -> (0, 3) -> (1, 1).
//  
//  
//  Example 3:
//  
//  Input: kx = 0, ky = 0, positions = [[1,2],[2,4]]
//  Output: 3
//  Explanation:
//  
//  Alice picks the pawn at (2, 4) and captures it in two moves: (0, 0) -> (1, 2) -> (2, 4). Note that the pawn at (1, 2) is not captured.
//  Bob picks the pawn at (1, 2) and captures it in one move: (2, 4) -> (1, 2).
//  
//  
//   
//  Constraints:
//  
//  0 <= kx, ky <= 49
//  1 <= positions.length <= 15
//  positions[i].length == 2
//  0 <= positions[i][0], positions[i][1] <= 49
//  All positions[i] are unique.
//  The input is generated such that positions[i] != [kx, ky] for all 0 <= i < positions.length.
//  
//  

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = 50;
        positions.push_back(vector<int>{kx, ky});
        int k = positions.size();
        vector<vector<vector<int>>> distance(k, vector<vector<int>>(n, vector<int>(n, - 1)));
        int directions[8][2] = {1, -2, -1, -2, 2, -1, 2, 1, 1, 2, -1, 2, -2, -1, -2, 1};
        for (int i = 0; i < k; i++) {
            queue<pair<int, int>> q;
            q.push(make_pair(positions[i][0], positions[i][1]));
            distance[i][positions[i][0]][positions[i][1]] = 0;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int d = 0; d < 8; d++){
                    int x = p.first + directions[d][0];
                    int y = p.second + directions[d][1];
                    if (x >= 0 && x < n && y >= 0 && y < n && distance[i][x][y] == - 1) {
                        distance[i][x][y] = distance[i][p.first][p.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }

        vector<vector<int>> cache(1 << k, vector<int>(k, 0));
        return helper(positions, distance, cache, 1 << (k - 1), k - 1);
    }

    int helper(vector<vector<int>>& positions, vector<vector<vector<int>>> & distance, vector<vector<int>> &cache, int mask, int last) {
        int n = positions.size();
        if (mask == (1 << n) - 1) {
            return 0;
        }

        if (cache[mask][last] == 0) {
            int count = __builtin_popcount(mask);
            int res = count & 1 ? INT_MIN: INT_MAX;
            for (int i = 0; i < n; i++) {
                if (!(mask >> i & 1)) {
                    int x = positions[i][0];
                    int y = positions[i][1];
                    if (count & 1) {
                        res = max(res, helper(positions, distance, cache, mask | 1 << i, i) + distance[last][x][y]);
                    } else {
                        res = min(res, helper(positions, distance, cache, mask | 1 << i, i) + distance[last][x][y]);
                    }
                }
            }
            cache[mask][last] = res;
        }

        return cache[mask][last];
    }

};

class Solution {
public:
    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        int n = 50;
        positions.push_back(vector<int>{kx, ky});
        int k = positions.size();
        vector<vector<vector<int>>> distance(k, vector<vector<int>>(n, vector<int>(n, - 1)));
        int directions[8][2] = {1, -2, -1, -2, 2, -1, 2, 1, 1, 2, -1, 2, -2, -1, -2, 1};
        for (int i = 0; i < k; i++) {
            queue<pair<int, int>> q;
            q.push(make_pair(positions[i][0], positions[i][1]));
            distance[i][positions[i][0]][positions[i][1]] = 0;
            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                for (int d = 0; d < 8; d++){
                    int x = p.first + directions[d][0];
                    int y = p.second + directions[d][1];
                    if (x >= 0 && x < n && y >= 0 && y < n && distance[i][x][y] == - 1) {
                        distance[i][x][y] = distance[i][p.first][p.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }

        vector<vector<int>> dp(1 << k, vector<int>(k, 0));
        for (int mask = (1 << k) - 2; mask > 0; mask--) {
            int count = __builtin_popcount(mask);
            for (int i = 0; i < k; i++) {
                dp[mask][i] = count & 1 ? INT_MIN: INT_MAX;
            }

            for (int i = 0; i < k; i++) {
                if (mask >> i & 1) {
                    for (int j = 0; j < k; j++) {
                        if (!(mask >> j & 1)) {
                            int x = positions[j][0];
                            int y = positions[j][1];

                            if (count & 1) {
                                dp[mask][i] = max(dp[mask][i], dp[mask | 1 << j][j] + distance[i][x][y]);
                            } else {
                                dp[mask][i] = min(dp[mask][i], dp[mask | 1 << j][j] + distance[i][x][y]);
                            }
                        }
                    }
                }
            }
        }

        return dp[1 << (k - 1)][k - 1];
    }
};