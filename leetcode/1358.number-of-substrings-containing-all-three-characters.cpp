//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/z1NZNOeQXGw

//  Given a string s consisting only of characters a, b and c.
//  Return the number of substrings containing at least one occurrence of all these characters a, b and c.
//   
//  Example 1:
//  
//  Input: s = "abcabc"
//  Output: 10
//  Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
//  
//  Example 2:
//  
//  Input: s = "aaacb"
//  Output: 3
//  Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
//  
//  Example 3:
//  
//  Input: s = "abc"
//  Output: 1
//  
//   
//  Constraints:
//  
//  3 <= s.length <= 5 x 10^4
//  s only consists of a, b or c characters.
//  
//  

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> counter = vector<int>(3, 0);
        int count = 0;
        int res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j] - 'a'] += 1;
            if (counter[s[j] - 'a'] == 1) {
                count += 1;
            }

            while (count == 3) {
                res += n - j;
                counter[s[i] - 'a'] -= 1;
                if (counter[s[i] - 'a'] == 0) {
                    count -= 1;
                }
                i += 1;
            }

        }
        return res;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> counter = vector<int>(3, 0);
        int count = 0;
        int res = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j] - 'a'] += 1;
            if (counter[s[j] - 'a'] == 1) {
                count += 1;
            }

            while (count == 3) {
                counter[s[i] - 'a'] -= 1;
                if (counter[s[i] - 'a'] == 0) {
                    count -= 1;
                }
                i += 1;
            }

            res += i;
        }
        return res;
    }
};