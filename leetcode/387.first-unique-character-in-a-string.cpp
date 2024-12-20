//  Tag: Hash Table, String, Queue, Counting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
//   
//  Example 1:
//  
//  Input: s = "leetcode"
//  Output: 0
//  Explanation:
//  The character 'l' at index 0 is the first character that does not occur at any other index.
//  
//  Example 2:
//  
//  Input: s = "loveleetcode"
//  Output: 2
//  
//  Example 3:
//  
//  Input: s = "aabb"
//  Output: -1
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists of only lowercase English letters.
//  
//  

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for (char x: s) {
            count[x] += 1;
        }

        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int firstUniqChar(string s) {
        string letters = "abcdefghijklmnopqrstuvwxyz";
        int index = s.size();

        for (char l : letters) {
            int left = s.find(l);
            int right = s.rfind(l);
            if (left >= 0 && left == right) {
                index = min(index, left);
            }
        }
        
        return index == s.size() ? -1 : index;
    }
};