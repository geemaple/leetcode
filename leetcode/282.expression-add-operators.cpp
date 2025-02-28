//  Tag: Math, String, Backtracking
//  Time: O(2^N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
//  Note that operands in the returned expressions should not contain leading zeros.
//   
//  Example 1:
//  
//  Input: num = "123", target = 6
//  Output: ["1*2*3","1+2+3"]
//  Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
//  
//  Example 2:
//  
//  Input: num = "232", target = 8
//  Output: ["2*3+2","2+3*2"]
//  Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
//  
//  Example 3:
//  
//  Input: num = "3456237490", target = 9191
//  Output: []
//  Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
//  
//   
//  Constraints:
//  
//  1 <= num.length <= 10
//  num consists of only digits.
//  -231 <= target <= 231 - 1
//  
//  

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        helper(num, 0, 0, 0, target, "", res);
        return res;
    }

    void helper(string &num, int index, long long pre, long long value, int target, string ans, vector<string> &res) {
        int n = num.size();
        if (index == n) {
            if (value == target) {
                res.push_back(ans);
            }
            return;
        }

        long long cur = 0;
        string expr = "";
        for (int i = index; i < n; i ++) {
            cur = cur * 10 + num[i] - '0';
            expr += num[i];

            if (index == 0) {
                helper(num, i + 1, cur, cur, target, expr, res);
            } else {
                helper(num, i + 1, cur, value + cur, target, ans + "+" + expr, res);
                helper(num, i + 1, -cur, value - cur, target, ans + "-" + expr, res);
                helper(num, i + 1, pre * cur, value - pre + pre * cur, target, ans + "*" + expr, res);
            }

            if (num[index] == '0') {
                break;
            } 
        }
    }
};