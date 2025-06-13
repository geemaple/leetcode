//  Tag: Enumerate, Array
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-243
//  Note: -

//  Given a list of `words` and two words `word1` and `word2`, return the shortest distance between these two words in the list.
//  
//  **Example 1:**
//  ```
//  Input：["practice", "makes", "perfect", "coding", "makes"],"coding","practice"
//  Output：3
//  Explanation：index("coding") - index("practice") = 3
//  ```
//  
//  
//  **Example 2:**
//  ```
//  Input：["practice", "makes", "perfect", "coding", "makes"],"makes","coding"
//  Output：1
//  Explanation：index("makes") - index("coding") = 1
//  ```
//  
//  You may assume that `word1 does not equal to word2`, and word1 and word2 are `both` in the list.

class Solution {
public:
    /**
     * @param words: a list of words
     * @param word1: a string
     * @param word2: a string
     * @return: the shortest distance between word1 and word2 in the list
     */
    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        // Write your code here
        int n = words.size();
        int res = n;
        int a = -1;
        int b = -1;
        for (int i = 0; i < n; i++) {
            if (words[i] == word1) {
                a = i;
            } else if (words[i] == word2) {
                b = i;
            }
            if (a >= 0 && b >= 0) {
                res = min(res, abs(a - b));
            }
        }
        return res;
    }
};