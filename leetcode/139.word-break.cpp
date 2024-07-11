//  Tag: Array, Hash Table, String, Dynamic Programming, Trie, Memoization
//  Time: O(MN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//  Note that the same word in the dictionary may be reused multiple times in the segmentation.
//   
//  Example 1:
//  
//  Input: s = "leetcode", wordDict = ["leet","code"]
//  Output: true
//  Explanation: Return true because "leetcode" can be segmented as "leet code".
//  
//  Example 2:
//  
//  Input: s = "applepenapple", wordDict = ["apple","pen"]
//  Output: true
//  Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//  Note that you are allowed to reuse a dictionary word.
//  
//  Example 3:
//  
//  Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//  Output: false
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 300
//  1 <= wordDict.length <= 1000
//  1 <= wordDict[i].length <= 20
//  s and wordDict[i] consist of only lowercase English letters.
//  All the strings of wordDict are unique.
//  
//  

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int l = 1; l <= n; l++) {
            for (auto word: wordDict) {
                int k = word.size();
                if (l >= k && s.substr(l - k, k) == word && dp[l - k]) {
                    dp[l] = true;
                    break;
                }
            }
        }

        return dp[n];
        
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        set<string>wordSet(wordDict.begin(), wordDict.end());
        for (int l = 1; l <= n; l++) {
            for (int i = 0; i < l; i++) {
                string sub = s.substr(i, l - i);
                if (wordSet.count(sub) > 0 && dp[i]) {
                    dp[l] = true;
                    break;
                }
            }
        }

        return dp[n];
        
    }
};