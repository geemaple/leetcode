//  Tag: String
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/wMmMR-2ZyU4

//  Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
//  Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.
//  You are given a string word, which represents the final output displayed on Alice's screen.
//  Return the total number of possible original strings that Alice might have intended to type.
//   
//  Example 1:
//  
//  Input: word = "abbcccc"
//  Output: 5
//  Explanation:
//  The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".
//  
//  Example 2:
//  
//  Input: word = "abcd"
//  Output: 1
//  Explanation:
//  The only possible string is "abcd".
//  
//  Example 3:
//  
//  Input: word = "aaaa"
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= word.length <= 100
//  word consists only of lowercase English letters.
//  
//  

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int res = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) {
                res += 1;
            }
        }
        return res;
    }
};