//  Tag: Hash Table, String, Stack, Greedy, Heap (Priority Queue)
//  Time: O(NLogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/5NHjE9SKC9U

//  You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
//  While there is a '*', do the following operation:
//  
//  Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
//  
//  Return the lexicographically smallest resulting string after removing all '*' characters.
//   
//  Example 1:
//  
//  Input: s = "aaba*"
//  Output: "aab"
//  Explanation:
//  We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
//  
//  Example 2:
//  
//  Input: s = "abc"
//  Output: "abc"
//  Explanation:
//  There is no '*' in the string.
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s consists only of lowercase English letters and '*'.
//  The input is generated such that it is possible to delete all '*' characters.
//  
//  

class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;
        vector<bool> removed(n, false);

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                auto [small, index] = heap.top();
                heap.pop();
                removed[index] = true; 
            } else {
                heap.emplace(-s[i], i);
            }
        }

        string res = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '*' && !removed[i]) {
                res += s[i];
            }
        }
        return res;
    }
};