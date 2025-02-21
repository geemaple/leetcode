//  Tag: String
//  Time: O(|S|)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
//  A substring is a contiguous sequence of characters within a string.
//   
//  Example 1:
//  Input: s = "0110", n = 3
//  Output: true
//  Example 2:
//  Input: s = "0110", n = 4
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 1000
//  s[i] is either '0' or '1'.
//  1 <= n <= 109
//  
//  

class Solution {
public:
    bool queryString(string s, int n) {
        int bits = ceil(log2(n + 1));
        unordered_set<int> table;
        int mask = 0;

        for (int k = 1; k <= bits; k++) { // 32 times most
            mask = (mask << 1) + 1;
            long long num = 0;
            for (int i = 0; i < s.size(); i++) {
                num = ((num << 1) + s[i] - '0') & mask;
                if (i >= k - 1) {
                    if (num <= n && num > 0) {
                        table.insert(num);
                    }
                }
            }
        }

        return table.size() == n;
    }
};