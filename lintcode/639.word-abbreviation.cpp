//  Tag: Hash Table
//  Time: O(NL)
//  Space: O(N)
//  Ref: Leetcode-527
//  Note: -

//  Given an array of n distinct non-empty strings, you need to generate **minimal** possible abbreviations for every word following rules below.
//  
//  1.
//  Begin with the first character and then the number of characters abbreviated, which followed by the last character.
//  2.
//  If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique.
//  In other words, a final abbreviation cannot map to more than one original words.
//  3.
//  If the abbreviation doesn't make the word shorter, then keep it as original.
//  
//  **Example 1:**
//  ```
//  Input:
//  ["like","god","internal","me","internet","interval","intension","face","intrusion"]
//  Output:
//  ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
//  ```
//  
//  **Example 2:**
//  ```
//  Input:
//  ["where","there","is","beautiful","way"]
//  Output:
//  ["w3e","t3e","is","b7l","way"]
//  ```
//  
//  1. Both n and the length of each word will not exceed 400.
//  2. The length of each word is greater than 1.
//  3. The words consist of lowercase English letters only.
//  4. The return answers should be in the same order as the original array.

class Solution {
public:
    /**
     * @param dict: an array of n distinct non-empty strings
     * @return: an array of minimal possible abbreviations for every word
     */
    vector<string> wordsAbbreviation(vector<string> &dict) {
        // write your code here
        int n = dict.size();
        unordered_map<string, int> counter;
        vector<int> prefix(n, 1);
        vector<string> res;
        for (int i = 0; i < n; i++) {
            string abbr = abbreviate(dict[i], prefix[i]);
            res.push_back(abbr);
            counter[abbr] += 1;
        }

        bool duplicated = true;
        while (duplicated) {
            duplicated = false;
            for (int i = 0; i < n; i++) {
                string abbr = res[i];
                if (counter[abbr] > 1) {
                    duplicated = true;
                    prefix[i] += 1;
                    string new_abbr = abbreviate(dict[i], prefix[i]);
                    res[i] = new_abbr;
                    counter[new_abbr] += 1;
                }
            }
        }

        return res;
    }

    string abbreviate(string word, int pos) {
        int n = word.size();
        if (pos + 2 >= n) {
            return word;
        }

        return word.substr(0, pos) + to_string(n - 1 - pos) + word.substr(n - 1, 1);
    }

};