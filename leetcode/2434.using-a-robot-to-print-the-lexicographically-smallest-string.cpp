//  Tag: Hash Table, String, Stack, Greedy
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/OTKMBmbEoHo

//  You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:
//  
//  Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
//  Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
//  
//  Return the lexicographically smallest string that can be written on the paper.
//   
//  Example 1:
//  
//  Input: s = "zza"
//  Output: "azz"
//  Explanation: Let p denote the written string.
//  Initially p="", s="zza", t="".
//  Perform first operation three times p="", s="", t="zza".
//  Perform second operation three times p="azz", s="", t="".
//  
//  Example 2:
//  
//  Input: s = "bac"
//  Output: "abc"
//  Explanation: Let p denote the written string.
//  Perform first operation twice p="", s="c", t="ba". 
//  Perform second operation twice p="ab", s="c", t="". 
//  Perform first operation p="ab", s="", t="c". 
//  Perform second operation p="abc", s="", t="".
//  
//  Example 3:
//  
//  Input: s = "bdda"
//  Output: "addb"
//  Explanation: Let p denote the written string.
//  Initially p="", s="bdda", t="".
//  Perform first operation four times p="", s="", t="bdda".
//  Perform second operation four times p="addb", s="", t="".
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists of only English lowercase letters.
//  
//  

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        unordered_map<char, int> counter;
        for (auto &ch: s) {
            counter[ch] += 1;
        }

        stack<char> st;
        string res = "";
        char l = 'a';

        for (auto &ch: s) {
            st.push(ch);
            counter[ch] -= 1;
            while (l < 'z' && counter[l] == 0) {
                l += 1;
            }

            while (!st.empty() && st.top() <= l) {
                res += st.top();
                st.pop();
            }
        }
        return res;
    }   
};