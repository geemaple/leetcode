//  Tag: Two Pointers, String, Dynamic Programming
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/SbDNsalMz7A

//  There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
//  After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
//  When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
//  For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
//  You are given a string dominoes representing the initial state where:
//  
//  dominoes[i] = 'L', if the ith domino has been pushed to the left,
//  dominoes[i] = 'R', if the ith domino has been pushed to the right, and
//  dominoes[i] = '.', if the ith domino has not been pushed.
//  
//  Return a string representing the final state.
//   
//  Example 1:
//  
//  Input: dominoes = "RR.L"
//  Output: "RR.L"
//  Explanation: The first domino expends no additional force on the second domino.
//  
//  Example 2:
//  
//  
//  Input: dominoes = ".L.R...LR..L.."
//  Output: "LL.RR.LLRRLL.."
//  
//   
//  Constraints:
//  
//  n == dominoes.length
//  1 <= n <= 105
//  dominoes[i] is either 'L', 'R', or '.'.
//  
//  

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'R') {
                continue;
            }

            if (dominoes[i] == 'L') {
                left[i] = 0;
            } else if (i < n - 1 && left[i + 1] != INT_MAX) {
                left[i] = left[i + 1] + 1;
            }
        }

        int right = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'L') {
                right = INT_MAX;
            } else if (dominoes[i] == 'R') {
                right = 0;
            } else if (i > 0 && right != INT_MAX) {
                right += 1;
            }
            if (left[i] != right) {
                dominoes[i] = left[i] < right ? 'L' : 'R';
            }
        }
        return dominoes;
    }
};

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        string res = "";
        int i = 0;
        for (int j = 1; j < dominoes.length(); ++j) {
            if (dominoes[j] == '.') {
                continue;
            };

            if (i > 0) {
                res += dominoes[i];
            }

            int middle = j - i - 1;
            if (dominoes[i] == dominoes[j])
                res += string(middle, dominoes[i]);
            else if (dominoes[i] == 'L' && dominoes[j] == 'R')
                res += string(middle, '.');
            else
                res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
            i = j;
        }
        return res;
    }
};