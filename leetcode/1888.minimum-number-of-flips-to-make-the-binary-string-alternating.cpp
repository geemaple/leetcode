//  Tag: String, Dynamic Programming, Greedy, Sliding Window
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
//  
//  Type-1: Remove the character at the start of the string s and append it to the end of the string.
//  Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
//  
//  Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
//  The string is called alternating if no two adjacent characters are equal.
//  
//  For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
//  
//   
//  Example 1:
//  
//  Input: s = "111000"
//  Output: 2
//  Explanation: Use the first operation two times to make s = "100011".
//  Then, use the second operation on the third and sixth elements to make s = "101010".
//  
//  Example 2:
//  
//  Input: s = "010"
//  Output: 0
//  Explanation: The string is already alternating.
//  
//  Example 3:
//  
//  Input: s = "1110"
//  Output: 1
//  Explanation: Use the second operation on the second element to make s = "1010".
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s[i] is either '0' or '1'.
//  
//  

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        vector<int> counter = {0, 0};
        int outer = (n + 1) / 2;
        int inner = n - outer;
        int res = n;
        for (int i = 0; i < 2 * n; i++) {
            if (i >= n) {
                counter[(i - n) & 1] -= (s[i - n] - '0');
            }

            counter[i & 1] += (s[i % n] - '0');
            if (i >= n - 1) {
                int k = (i - n + 1) % 2;
                int count = min(outer - counter[k] + counter[1 - k], counter[k] + inner - counter[1 - k]);
                res = min(res, count);
            }
        }

        return res;
    }
};

class Solution {
public:
    int minFlips(string s) {
        int k = s.size();
        s += s; 
        int n = s.size();
        string s1 = "", s2 = "";

        for (int i = 0; i < n; ++i) {
            s1 += (i % 2 == 0) ? '1' : '0';
            s2 += (i % 2 == 1) ? '1' : '0';
        }

        int res = k;
        int count1 = 0, count2 = 0;


        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                if (s[i - k] != s1[i - k]) count1--;
                if (s[i - k] != s2[i - k]) count2--;
            }

            if (s[i] != s1[i]) count1++;
            if (s[i] != s2[i]) count2++;

            if (i >= k - 1) {
                res = min(res, min(count1, count2));
            }
        }

        return res;
    }
};