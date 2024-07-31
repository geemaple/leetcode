//  Tag: Array, String, Bit Manipulation
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.
//   
//  Example 1:
//  
//  Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
//  Output: 16
//  Explanation: The two words can be "abcw", "xtfn".
//  
//  Example 2:
//  
//  Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
//  Output: 4
//  Explanation: The two words can be "ab", "cd".
//  
//  Example 3:
//  
//  Input: words = ["a","aa","aaa","aaaa"]
//  Output: 0
//  Explanation: No such pair of words.
//  
//   
//  Constraints:
//  
//  2 <= words.length <= 1000
//  1 <= words[i].length <= 1000
//  words[i] consists only of lowercase English letters.
//  
//  

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n, 0);
        for (int i = 0; i < n; i++) {
            for (char ch: words[i]) {
                mask[i] |= 1 << (ch - 'a');
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((mask[i] & mask[j]) == 0) {
                    res = max(res, int(words[i].size() * words[j].size()));
                }
            }
        }
        return res;
    }
};