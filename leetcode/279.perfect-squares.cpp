//  Tag: Math, Dynamic Programming, Breadth-First Search
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer n, return the least number of perfect square numbers that sum to n.
//  A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
//   
//  Example 1:
//  
//  Input: n = 12
//  Output: 3
//  Explanation: 12 = 4 + 4 + 4.
//  
//  Example 2:
//  
//  Input: n = 13
//  Output: 2
//  Explanation: 13 = 4 + 9.
//  
//   
//  Constraints:
//  
//  1 <= n <= 104
//  
//  

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        queue<int> q;
        q.push(n);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                for (auto square: squares) {
                    int next_val = cur - square;
                    if (next_val == 0) {
                        return level;
                    }

                    if (next_val > 0) {
                        q.push(next_val);
                    } 
                }
            }
        }

        return level;
    }
};

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int res = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                res = min(res, dp[i - j * j] + 1);
            }
            dp[i] = res;
        }

        return dp[n];
    }
};