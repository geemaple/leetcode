//  Tag: Array, Two Pointers, String, Sorting
//  Time: O(NlogN + NM)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a string s and a string array dictionary, return the longest string in the dictionary that can be formed by deleting some of the given string characters. If there is more than one possible result, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
//   
//  Example 1:
//  
//  Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
//  Output: "apple"
//  
//  Example 2:
//  
//  Input: s = "abpcplea", dictionary = ["a","b","c"]
//  Output: "a"
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 1000
//  1 <= dictionary.length <= 1000
//  1 <= dictionary[i].length <= 1000
//  s and dictionary[i] consist of lowercase English letters.
//  
//  

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end(), [](string &a, string &b) {
            return a.size() == b.size() ? a < b : a.size() > b.size();
        });

        for (string &t : dictionary) {
            int k = 0;
            for (int i = 0; i < s.size(); i++) {
                if (k < t.size() && s[i] == t[k]) {
                    k++;
                }
            }

            if (k == t.size()) {
                return t;
            }
        }

        return "";
    }
};