//  Tag: String, Stack
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//  An input string is valid if:
//  
//  Open brackets must be closed by the same type of brackets.
//  Open brackets must be closed in the correct order.
//  Every close bracket has a corresponding open bracket of the same type.
//  
//   
//  Example 1:
//  
//  Input: s = "()"
//  Output: true
//  
//  Example 2:
//  
//  Input: s = "()[]{}"
//  Output: true
//  
//  Example 3:
//  
//  Input: s = "(]"
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 104
//  s consists of parentheses only '()[]{}'.
//  
//  

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> p = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };

        for (char ch: s) {
            if (p.count(ch) > 0) {
                st.push(p[ch]);
            } else {
                if (!st.empty() && ch == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};