//  Tag: Same Direction Two Pointers, Two Pointers, Hash Table, String
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-159
//  Note: -

//  Given a string, find the length of the longest substring T that contains at most `2` distinct characters.
//  
//  ---
//   
//  
//  ### Example 1
//  ```
//  Input: “eceba”
//  Output: 3
//  Explanation:
//  T is "ece" which its length is 3.
//  ```
//  
//  ### Example 2
//  ```
//  Input: “aaa”
//  Output: 3
//  ```
//  
//  

class Solution {
public:
    /**
     * @param s: a string
     * @return: the length of the longest substring T that contains at most 2 distinct characters
     */
    int lengthOfLongestSubstringTwoDistinct(string &s) {
        // Write your code here
        int n = s.size();
        unordered_map<char, int> counter;
        int i = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j]] += 1;
            while (counter.size() > 2) {
                counter[s[i]] -= 1;
                if (counter[s[i]] == 0) {
                    counter.erase(s[i]);
                }
                i += 1;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};