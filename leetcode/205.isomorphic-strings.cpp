//  Tag: Hash Table, String
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two strings s and t, determine if they are isomorphic.
//  Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//  All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
//   
//  Example 1:
//  Input: s = "egg", t = "add"
//  Output: true
//  Example 2:
//  Input: s = "foo", t = "bar"
//  Output: false
//  Example 3:
//  Input: s = "paper", t = "title"
//  Output: true
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 5 * 104
//  t.length == s.length
//  s and t consist of any valid ascii character.
//  
//  

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_mask(256, 0);
        vector<int> t_mask(256, 0);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s_mask[s[i]] != t_mask[t[i]]) {
                return false;
            }

            s_mask[s[i]] = t_mask[t[i]] = i + 1;
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> leftToRight(256, 0);
        vector<int> rightToLeft(256, 0);

        for (auto i = 0; i < s.size(); ++i) {

            if (leftToRight[s[i]] == 0) {
                leftToRight[s[i]] = t[i];
            } else if(leftToRight[s[i]] != t[i]) {
                return false;
            }

            if (rightToLeft[t[i]] == 0) {
                rightToLeft[t[i]] = s[i];
            } else if(rightToLeft[t[i]] != s[i]) {
                return false;
            }
        }

        return true;
    }
};