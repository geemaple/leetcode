//  Tag: Hash Table, String, Greedy
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
//  Letters are case sensitive, for example, "Aa" is not considered a palindrome.
//   
//  Example 1:
//  
//  Input: s = "abccccdd"
//  Output: 7
//  Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
//  
//  Example 2:
//  
//  Input: s = "a"
//  Output: 1
//  Explanation: The longest palindrome that can be built is "a", whose length is 1.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 2000
//  s consists of lowercase and/or uppercase English letters only.
//  
//  

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<int> set;
        int res = 0;
        for (auto x: s) {
            if (set.count(x) > 0) {
                res += 2;
                set.erase(x);
            } else {
                set.insert(x);
            }
        }

        if (!set.empty()) {
            res += 1;
        }

        return res;
    }
};