//  Tag: String
//  Time: O(2^N)
//  Space: O(2^N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/Lcp94z9vsxw

//  The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
//  
//  countAndSay(1) = "1"
//  countAndSay(n) is the run-length encoding of countAndSay(n - 1).
//  
//  Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".
//  Given a positive integer n, return the nth element of the count-and-say sequence.
//   
//  Example 1:
//  
//  Input: n = 4
//  Output: "1211"
//  Explanation:
//  
//  countAndSay(1) = "1"
//  countAndSay(2) = RLE of "1" = "11"
//  countAndSay(3) = RLE of "11" = "21"
//  countAndSay(4) = RLE of "21" = "1211"
//  
//  
//  Example 2:
//  
//  Input: n = 1
//  Output: "1"
//  Explanation:
//  This is the base case.
//  
//   
//  Constraints:
//  
//  1 <= n <= 30
//  
//   
//  Follow up: Could you solve it iteratively?

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        string ans = countAndSay(n - 1);
        string res = "";
        int count = 0;
        char pre = ans[0];

        for (auto &x: ans) {
            if (x == pre) {
                count += 1;
            } else {
                res += to_string(count) + pre;
                count = 1;
                pre = x;
            }
        }
        return res + to_string(count) + pre;
    }
};

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int k = 0; k < n - 1; k++) {
            string tmp = "";
            int count = 0;
            char pre = res[0];
            for (auto &x: res) {
                if (x == pre) {
                    count += 1;
                } else {
                    tmp += to_string(count) + pre;
                    count = 1;
                    pre = x;
                }
            }

            res = tmp + to_string(count) + pre;
        }

        return res;
    }
};