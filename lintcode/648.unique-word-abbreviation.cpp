//  Tag: Hash Table
//  Time: O(1)
//  Space: O(N)
//  Ref: Leetcode-288
//  Note: -

//  An abbreviation of a word follows the form ```<first letter><number><last letter>```, the number indicates the length of the abbreviated part.
//  Below are some examples of word abbreviations:
//  ```
//  a) it                      --> it    (no abbreviation)
//  
//       1
//  b) d|o|g                   --> d1g
//  
//                1    1  1
//       1---5----0----5--8
//  c) i|nternationalizatio|n  --> i18n
//  
//                1
//       1---5----0
//  d) l|ocalizatio|n          --> l10n
//  ```
//  Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
//  A word's abbreviation is unique if **no other word** from the dictionary has the same abbreviation.
//  
//  **Example1**
//  ```
//  Input:
//  [ "deer", "door", "cake", "card" ]
//  isUnique("dear")
//  isUnique("cart")
//  Output:
//  false
//  true
//  Explanation:
//  Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
//  "dear" 's abbreviation is "d2r" , in dictionary.
//  "cart" 's abbreviation is "c2t" , not in dictionary.
//  ```
//  **Example2**
//  ```
//  Input:
//  [ "deer", "door", "cake", "card" ]
//  isUnique("cane")
//  isUnique("make")
//  Output:
//  false
//  true
//  Explanation:
//  Dictionary's abbreviation is ["d2r", "d2r", "c2e", "c2d"].
//  "cane" 's abbreviation is "c2e" , in dictionary.
//  "make" 's abbreviation is "m2e" , not in dictionary.
//  ```
//  
//  

class ValidWordAbbr {
public:
    /*
    * @param dictionary: a list of words
    */
    unordered_map<string, unordered_set<string>> word_map;
    ValidWordAbbr(vector<string> dictionary) {
        // do intialization if necessary
        for (auto &x: dictionary) {
            word_map[abbreviate(x)].insert(x);
        }
    }

    /*
     * @param word: a string
     * @return: true if its abbreviation is unique or false
     */
    bool isUnique(string &word) {
        // write your code here
        string ab = abbreviate(word);
        return word_map[ab].count(word) == word_map[ab].size();
    }

    string abbreviate(string &word) {
        if (word.size() <= 2) {
            return word;
        } else {
            return word[0] + to_string(word.size() - 2) + word.back();
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param = obj.isUnique(word);
 */