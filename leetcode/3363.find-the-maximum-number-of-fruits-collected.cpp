//  Tag: Array, Dynamic Programming, Matrix
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: TODO

//  There is a game dungeon comprised of n x n rooms arranged in a grid.
//  You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).
//  The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):
//  
//  The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
//  The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
//  The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
//  
//  When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.
//  Return the maximum number of fruits the children can collect from the dungeon.
//   
//  Example 1:
//  
//  Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]
//  Output: 100
//  Explanation:
//  
//  In this example:
//  
//  The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
//  The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
//  The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
//  
//  In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.
//  
//  Example 2:
//  
//  Input: fruits = [[1,1],[1,1]]
//  Output: 4
//  Explanation:
//  In this example:
//  
//  The 1st child moves on the path (0,0) -> (1,1).
//  The 2nd child moves on the path (0,1) -> (1,1).
//  The 3rd child moves on the path (1,0) -> (1,1).
//  
//  In total they collect 1 + 1 + 1 + 1 = 4 fruits.
//  
//   
//  Constraints:
//  
//  2 <= n == fruits.length == fruits[i].length <= 1000
//  0 <= fruits[i][j] <= 1000
//  
//  

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i < j && j < n - 1 - i) {
                    fruits[i][j] = 0;
                }
                if (j < i && i < n - 1 - j) {
                    fruits[i][j] = 0;
                }
            }
        }

        int child1 = 0;
        for (int i = 0; i < n; ++i) {
            child1 += fruits[i][i];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (j + 1 < n) {
                    fruits[i][j] += max({fruits[i - 1][j], fruits[i - 1][j - 1], fruits[i - 1][j + 1]});
                } else {
                    fruits[i][j] += max(fruits[i - 1][j], fruits[i - 1][j - 1]);
                }
            }
        }
        int child2 = fruits[n - 2][n - 1];

        for (int j = 1; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                if (i + 1 < n) {
                    fruits[i][j] += max({fruits[i][j - 1], fruits[i - 1][j - 1], fruits[i + 1][j - 1]});
                } else {
                    fruits[i][j] += max(fruits[i][j - 1], fruits[i - 1][j - 1]);
                }
            }
        }
        int child3 = fruits[n - 1][n - 2];

        return child1 + child2 + child3;
    }
};

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        int child1 = 0;
        
        for (int i = 0; i < n; ++i) {
            child1 += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];
        for (int i = 1; i < n; ++i) {
            for (int j = n - i - 1; j < n; ++j) {
                if (j == 0) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j + 1]) + fruits[i][j];
                } else if (j == n - 1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + fruits[i][j];
                } else {
                    dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + fruits[i][j];
                }
            }
        }
        
        int child2 = dp[n - 1][n - 1];
        int j = n - 1;
        
        for (int i = n - 1; i > 0; --i) {
            int val = fruits[i][j];
            fruits[i][j] = 0;
            if (j > 0 && dp[i - 1][j - 1] + val == dp[i][j]) {
                j = j - 1;
            } else if (j < n - 1 && dp[i - 1][j + 1] + val == dp[i][j]) {
                j = j + 1;
            }
        }
        
        fill(dp.begin(), dp.end(), vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];
        
        for (int j = 1; j < n; ++j) {
            for (int i = n - j - 1; i < n; ++i) {
                if (i == 0) {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j - 1]) + fruits[i][j];
                } else if (i == n - 1) {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1]) + fruits[i][j];
                } else {
                    dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]}) + fruits[i][j];
                }
            }
        }
        
        int child3 = dp[n - 1][n - 1];
        return child1 + child2 + child3;
    }
};