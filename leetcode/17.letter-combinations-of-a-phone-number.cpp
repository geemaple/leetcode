//  Tag: Hash Table, String, Backtracking
//  Time: O(4^N)
//  Space: O(4^N)
//  Ref: -
//  Note: -

//  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//  A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//  
//   
//  Example 1:
//  
//  Input: digits = "23"
//  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//  
//  Example 2:
//  
//  Input: digits = ""
//  Output: []
//  
//  Example 3:
//  
//  Input: digits = "2"
//  Output: ["a","b","c"]
//  
//   
//  Constraints:
//  
//  0 <= digits.length <= 4
//  digits[i] is a digit in the range ['2', '9'].
//  
//  

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> graph = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
            };

        vector<string> res;
        helper(graph, digits, 0, "", res);
        return res;
    }

    void helper(unordered_map<char, string> &graph, string &digits, int index, string ans, vector<string> &res) {
        if (index == digits.size()) {
            res.push_back(ans);
            return;
        }

        for (auto &ch: graph[digits[index]]) {
            helper(graph, digits, index + 1, ans + ch, res);
        }
    }
};