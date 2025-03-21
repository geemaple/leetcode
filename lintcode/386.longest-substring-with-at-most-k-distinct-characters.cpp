//  Tag: Same Direction Two Pointers, Two Pointers
//  Time: O(N)
//  Space: O(K)
//  Ref: Leetcode-340
//  Note: -

//  Given a string *S*, find the length of the longest substring *T* that contains at most k distinct characters.
//  
//  **Example 1:**
//  
//  ```
//  Input: S = "eceba" and k = 3
//  Output: 4
//  Explanation: T = "eceb"
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: S = "WORLD" and k = 4
//  Output: 4
//  Explanation: T = "WORL" or "ORLD"
//  ```
//  
//  

class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int n = s.size();
        unordered_map<char, int> counter;
        int i = 0;
        int res = 0;
        for (int j = 0; j < n; j++) {
            counter[s[j]] += 1;
            while (counter.size() > k) {
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