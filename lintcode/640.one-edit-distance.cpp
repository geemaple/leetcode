//  Tag: Enumerate, Simulation, String
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-161
//  Note: -

//  Given two strings S and T, determine if they are both one edit distance apart.
//  One edit distance means doing one of these operation:
//  - insert one character in any position of S
//  - delete one character in S
//  - change any one character in S to other character
//  
//  Example 1:
//  ```
//  Input: s = "aDb", t = "adb" 
//  Output: true
//  ```
//  Example 2:
//  ```
//  Input: s = "ab", t = "ab" 
//  Output: false
//  Explanation:
//  s=t ,so they aren't one edit distance apart
//  ```
//  
//  

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int size_s = s.size();
        int size_t = t.size();
        
        if (size_s == size_t) { //replace
            int diff = 0;
            for(auto i = 0; i < s.size(); ++i) {
                if (s[i] != t[i]) {
                    if (++diff > 1){
                        break;
                    }
                }
            }
            
            return diff == 1;
        }
        
        if (abs(size_s - size_t) == 1) { //delete or insert
            string& small = size_s > size_t ? t: s;
            string& large = size_s < size_t ? t: s;
            int diff = 0;
       
            for (auto i = 0; i < large.size(); ++i) {
                if (i - diff >= small.size() || small[i - diff] != large[i]) {
                    if (++diff > 1) {
                        break;
                    }
                }
            }
            return diff == 1;
        }
        
        return false;
    }
};

class Solution {
public:
    /**
     * @param s: a string
     * @param t: a string
     * @return: true if they are both one edit distance apart or false
     */
    bool isOneEditDistance(string &s, string &t) {
        // write your code here
        int n = s.size();
        int m = t.size();
        if (abs(n - m) > 1) {
            return false;
        }

        if (n > m) {
            return isOneEditDistance(t, s);
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                if (m == n) {
                    return s.substr(i + 1) == t.substr(i + 1);
                } else {
                    return s.substr(i) == t.substr(i + 1);
                }
            }
        }

        return n + 1 == m;
    }
};