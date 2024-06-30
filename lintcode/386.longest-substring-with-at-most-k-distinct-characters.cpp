//  Tag: Same Direction Two Pointers, Two Pointers
//  Time: O(N)
//  Space: O(K)
//  Ref: -
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
        unordered_map<char, int> table;
        int count = 0;
        int l = 0;
        int length = 0;    
    
        for (int r = 0; r < s.size(); r++) {
            if (table[s[r]] == 0) {
                count += 1;
            }
            table[s[r]] += 1;

            while (count > k) {
                if (table[s[l]] == 1) {
                    count -= 1;
                }
                table[s[l]] -= 1;
                l++;
            }

            if (r - l + 1 > length) {
                length = r - l + 1;
            } 
        }

        return length;
    }
};