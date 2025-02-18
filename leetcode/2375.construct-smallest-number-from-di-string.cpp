//  Tag: String, Backtracking, Stack, Greedy
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/P8i_9XLrj3w

//  You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.
//  A 0-indexed string num of length n + 1 is created using the following conditions:
//  
//  num consists of the digits '1' to '9', where each digit is used at most once.
//  If pattern[i] == 'I', then num[i] < num[i + 1].
//  If pattern[i] == 'D', then num[i] > num[i + 1].
//  
//  Return the lexicographically smallest possible string num that meets the conditions.
//   
//  Example 1:
//  
//  Input: pattern = "IIIDIDDD"
//  Output: "123549876"
//  Explanation:
//  At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
//  At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
//  Some possible values of num are "245639871", "135749862", and "123849765".
//  It can be proven that "123549876" is the smallest possible num that meets the conditions.
//  Note that "123414321" is not possible because the digit '1' is used more than once.
//  Example 2:
//  
//  Input: pattern = "DDD"
//  Output: "4321"
//  Explanation:
//  Some possible values of num are "9876", "7321", and "8742".
//  It can be proven that "4321" is the smallest possible num that meets the conditions.
//  
//   
//  Constraints:
//  
//  1 <= pattern.length <= 8
//  pattern consists of only the letters 'I' and 'D'.
//  
//  

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        vector<bool> used(10, false);
        vector<int> res(n + 1, 0);
        
        helper(pattern, 0, res, used);

        string result;
        for (int num : res) {
            result += to_string(num);
        }
        return result;
    }

    bool helper(const string &pattern, int i, vector<int> &res, vector<bool> &used) {
        if (i == res.size()) {
            return true;
        }

        for (int num = 1; num <= 9; num++) {
            if (used[num]) continue;
            if (i == 0 ||
                (pattern[i - 1] == 'I' && num > res[i - 1]) || 
                (pattern[i - 1] == 'D' && num < res[i - 1])) {
                res[i] = num;
                used[num] = true;
                if (helper(pattern, i + 1, res, used)) {
                    return true;
                }
                res[i] = 0;
                used[num] = false;
            }
        }

        return false;
    }
};

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string res;
        stack<char> st;
        for (int i = 0; i <= n; i++) {
            st.push('1' + i);
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    res += st.top();
                    st.pop();
                }
            }
        }
        return res;
    }
};