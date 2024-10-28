//  Tag: Hash Table, String, Counting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
//  Each letter in magazine can only be used once in ransomNote.
//   
//  Example 1:
//  Input: ransomNote = "a", magazine = "b"
//  Output: false
//  Example 2:
//  Input: ransomNote = "aa", magazine = "ab"
//  Output: false
//  Example 3:
//  Input: ransomNote = "aa", magazine = "aab"
//  Output: true
//  
//   
//  Constraints:
//  
//  1 <= ransomNote.length, magazine.length <= 105
//  ransomNote and magazine consist of lowercase English letters.
//  
//  

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if (ransomNote.size() > magazine.size()) {
            return false;
        }

        vector<int> counter(26, 0);
        for (auto x: magazine) {
            counter[x - 'a'] += 1;
        }

        for (auto x: ransomNote) {
            if (counter[x - 'a'] == 0) {
                return false;
            }
            counter[x - 'a'] -= 1;
        }

        return true;
    }
};