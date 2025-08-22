//  Tag: Array, Math, Backtracking
//  Time: O(4！ * 4 ^ 3)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/qZSvcFSpO6o

//  You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.
//  You are restricted with the following rules:
//  
//  The division operator '/' represents real division, not integer division.
//  
//  	
//  For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
//  
//  
//  Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
//  	
//  For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
//  
//  
//  You cannot concatenate numbers together
//  	
//  For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
//  
//  
//  
//  Return true if you can get such expression that evaluates to 24, and false otherwise.
//   
//  Example 1:
//  
//  Input: cards = [4,1,8,7]
//  Output: true
//  Explanation: (8-4) * (7-1) = 24
//  
//  Example 2:
//  
//  Input: cards = [1,2,1,2]
//  Output: false
//  
//   
//  Constraints:
//  
//  cards.length == 4
//  1 <= cards[i] <= 9
//  
//  

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        sort(cards.begin(), cards.end());

        do {
            unordered_set<double> res = dfs(cards, 0, 3);
            for (auto &x: res) {
                if (abs(x - 24) < 1e-9) {
                    return true;
                }
            }
        } while (next_permutation(cards.begin(), cards.end()));

        return false;
    }

    unordered_set<double> dfs(vector<int>& cards, int l, int r) {
        unordered_set<double> res;
        if (l == r) {
            res.insert(cards[l]);
        } else {
            for (int m = l; m < r; m++) {
                unordered_set<double> left = dfs(cards, l, m);
                unordered_set<double> right = dfs(cards, m + 1, r);
                for (auto &a : left) {
                    for (auto &b : right) {
                        res.insert(a + b);
                        res.insert(a - b);
                        res.insert(a * b);
                        if (b != 0) {
                            res.insert(a / b);
                        }
                    }
                }
            }
        }
        return res;
    }
};