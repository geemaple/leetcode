//  Tag: Dynamic Programming, Memoization
//  Time: O(NlogN)
//  Space: O(logN)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/UYUMIzKGFFc

//  There is a tournament where n players are participating. The players are standing in a single row and are numbered from 1 to n based on their initial standing position (player 1 is the first player in the row, player 2 is the second player in the row, etc.).
//  The tournament consists of multiple rounds (starting from round number 1). In each round, the ith player from the front of the row competes against the ith player from the end of the row, and the winner advances to the next round. When the number of players is odd for the current round, the player in the middle automatically advances to the next round.
//  
//  For example, if the row consists of players 1, 2, 4, 6, 7
//  
//  Player 1 competes against player 7.
//  Player 2 competes against player 6.
//  Player 4 automatically advances to the next round.
//  
//  
//  
//  After each round is over, the winners are lined back up in the row based on the original ordering assigned to them initially (ascending order).
//  The players numbered firstPlayer and secondPlayer are the best in the tournament. They can win against any other player before they compete against each other. If any two other players compete against each other, either of them might win, and thus you may choose the outcome of this round.
//  Given the integers n, firstPlayer, and secondPlayer, return an integer array containing two values, the earliest possible round number and the latest possible round number in which these two players will compete against each other, respectively.
//   
//  Example 1:
//  
//  Input: n = 11, firstPlayer = 2, secondPlayer = 4
//  Output: [3,4]
//  Explanation:
//  One possible scenario which leads to the earliest round number:
//  First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
//  Second round: 2, 3, 4, 5, 6, 11
//  Third round: 2, 3, 4
//  One possible scenario which leads to the latest round number:
//  First round: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11
//  Second round: 1, 2, 3, 4, 5, 6
//  Third round: 1, 2, 4
//  Fourth round: 2, 4
//  
//  Example 2:
//  
//  Input: n = 5, firstPlayer = 1, secondPlayer = 5
//  Output: [1,1]
//  Explanation: The players numbered 1 and 5 compete in the first round.
//  There is no way to make them compete in any other round.
//  
//   
//  Constraints:
//  
//  2 <= n <= 28
//  1 <= firstPlayer < secondPlayer <= n
//  
//  

class Solution {
public:
    int min_r = INT_MAX, max_r = INT_MIN;
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        dfs(firstPlayer, n - secondPlayer + 1, n, 1);
        return { min_r, max_r };
    }

    void dfs(int l, int r, int n, int round) {
        if (l == r) {
            min_r = min(min_r, round);
            max_r = max(max_r, round);
            return;
        }

        if (l > r) {
            swap(l, r);
        }

        for (int i = 1; i <= l; i++) {
            for (int j = l - i + 1; i <= min(r - i, (n + 1) / 2 - i); j++) {
                if (l - i + r - j <= n / 2) {
                    dfs(i, j, (n + 1) / 2, round + 1);
                }
            }
        }
    }
};

class Solution {
public:
    int min_r = INT_MAX, max_r = INT_MIN;
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        dfs(n, (1 << n) - 1, 1, 0, n - 1, firstPlayer - 1, secondPlayer - 1);
        return { min_r, max_r };
    }

    void dfs(int n, int mask, int round, int i, int j, int first, int second) {
        if (i >= j)
            dfs(n, mask, round + 1, 0, n - 1, first, second);
        else if (n, (mask & (1 << i)) == 0)
            dfs(n, mask, round, i + 1, j, first, second);
        else if ((mask & (1 << j)) == 0)
            dfs(n, mask, round, i, j - 1, first, second);
        else if (i == first && j == second) {
            min_r = min(min_r, round);
            max_r = max(max_r, round);
        }
        else {
            if (i != first && i != second)
                dfs(n, mask ^ (1 << i), round, i + 1, j - 1, first, second);
            if (j != first && j != second)
                dfs(n, mask ^ (1 << j), round, i + 1, j - 1, first, second);
        }
    }
};