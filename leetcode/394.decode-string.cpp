//  Tag: String, Stack, Recursion
//  Time: O(A)
//  Space: O(A)
//  Ref: -
//  Note: -

//  Given an encoded string, return its decoded string.
//  The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
//  You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
//  The test cases are generated so that the length of the output will never exceed 105.
//   
//  Example 1:
//  
//  Input: s = "3[a]2[bc]"
//  Output: "aaabcbc"
//  
//  Example 2:
//  
//  Input: s = "3[a2[c]]"
//  Output: "accaccacc"
//  
//  Example 3:
//  
//  Input: s = "2[abc]3[cd]ef"
//  Output: "abcabccdcdcdef"
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 30
//  s consists of lowercase English letters, digits, and square brackets '[]'.
//  s is guaranteed to be a valid input.
//  All the integers in s are in the range [1, 300].
//  
//  

class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        for (auto x: s) {
            if (x == ']') {
                string seg = "";
                while (st.top() != '[') {
                    seg = st.top() + seg;
                    st.pop();
                }
                st.pop();
                int count = 0;
                int power = 1;
                while (!st.empty() && isdigit(st.top())) {
                    count = (st.top() - '0') * power + count;
                    power *= 10;
                    st.pop();
                }

                for (int i = 0; i < count; i++) {
                    for (int j = 0; j < seg.size(); j++) {
                        st.push(seg[j]);
                    }
                }
            } else {
                st.push(x);
            }
        }

        string res = "";
        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};