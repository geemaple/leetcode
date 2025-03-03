//  Tag: Hash Table, String, Sliding Window
//  Time: -
//  Space: -
//  Ref: -
//  Note: -
//  Video: https://youtu.be/_tyJM7UjGlo

//  You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.
//  Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.
//   
//  Example 1:
//  
//  Input: s = "aabaaaacaabc", k = 2
//  Output: 8
//  Explanation: 
//  Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
//  Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
//  A total of 3 + 5 = 8 minutes is needed.
//  It can be proven that 8 is the minimum number of minutes needed.
//  
//  Example 2:
//  
//  Input: s = "a", k = 1
//  Output: -1
//  Explanation: It is not possible to take one 'b' or 'c' so return -1.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists of only the letters 'a', 'b', and 'c'.
//  0 <= k <= s.length
//  
//  

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> counter(3, 0);
        for (char x: s) {
            counter[x - 'a'] += 1;
        }

        for (int i = 0; i < 3; i++) {
            if (counter[i] < k) {
                return -1;
            }
            counter[i] -= k;
        }
 
        int i = 0;
        int res = 0;
        vector<int> tmp(3, 0);
        for(int j = 0; j < n; j++) {
            tmp[s[j] - 'a'] += 1;
            while (tmp[s[j] - 'a'] > counter[s[j] - 'a']) {
                tmp[s[i] - 'a'] -= 1;
                i += 1;
            }
            res = max(res, j - i + 1);
        }

        return n - res;
    }
};