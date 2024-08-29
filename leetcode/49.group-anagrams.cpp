//  Tag: Array, Hash Table, String, Sorting
//  Time: O(NL)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
//   
//  Example 1:
//  Input: strs = ["eat","tea","tan","ate","nat","bat"]
//  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//  Example 2:
//  Input: strs = [""]
//  Output: [[""]]
//  Example 3:
//  Input: strs = ["a"]
//  Output: [["a"]]
//  
//   
//  Constraints:
//  
//  1 <= strs.length <= 104
//  0 <= strs[i].length <= 100
//  strs[i] consists of lowercase English letters.
//  
//  

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        vector<vector<string>> res;
        
        for (auto str: strs){
            string key = str;
            sort(key.begin(), key.end());
            map[key].push_back(str);
        }

        for (auto &[key, val]: map) {
            res.push_back(val);
        }
        
        return res;
    }
};