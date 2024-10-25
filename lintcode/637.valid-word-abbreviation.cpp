//  Tag: String, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-408
//  Note: -

//  Given a **non-empty** string `word` and an abbreviation `abbr`, return whether the string matches with the given abbreviation.
//  
//  A string such as `"word"` contains only the following valid abbreviations:
//  ```
//  ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//  ```
//  
//  **Example 1:**
//  ```
//  Input : s = "internationalization", abbr = "i12iz4n"
//  Output : true
//  ```
//  **Example 2:**
//  ```
//  Input : s = "apple", abbr = "a2e"
//  Output : false
//  ```
//  
//  Where 1 means one character is omitted, 2 means two characters are omitted, and so on.
//  Notice that only the above abbreviations are valid abbreviations of the string `word`. Any other string is not a valid abbreviation of `word`.

class Solution {
public:
    /**
     * @param word: a non-empty string
     * @param abbr: an abbreviation
     * @return: true if string matches with the given abbr or false
     */
    bool validWordAbbreviation(string &word, string &abbr) {
        // write your code here
        int i = 0;
        int j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                i++;
                j++;
            } else if (isdigit(abbr[j]) && abbr[j] != '0') {
                int num = 0;
                while (j < abbr.size() && isdigit(abbr[j])) {
                    num = num * 10 + abbr[j] - '0';
                    j++;
                }
                i += num;
            } else {
                return false;
            }
        }

        return i == word.size() && j == abbr.size();
    }
};