//  Tag: Hash Table, String, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
//   
//  Example 1:
//  
//  Input: s = "bcbbbcba"
//  Output: 4
//  Explanation:
//  The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
//  Example 2:
//  
//  Input: s = "aaaa"
//  Output: 2
//  Explanation:
//  The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".
//   
//  Constraints:
//  
//  2 <= s.length <= 100
//  s consists only of lowercase English letters.
//  
//  

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> counter;
        int i = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            while (counter[s[j]] == 2) {
                counter[s[i]] -= 1;
                i += 1;
            }

            counter[s[j]] += 1;
            res = max(res, j - i + 1);
        }
        return res;
    }
};