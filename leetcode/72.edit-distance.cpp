//  Tag: String, Dynamic Programming
//  Time: O(MN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
//  You have the following three operations permitted on a word:
//  
//  Insert a character
//  Delete a character
//  Replace a character
//  
//   
//  Example 1:
//  
//  Input: word1 = "horse", word2 = "ros"
//  Output: 3
//  Explanation: 
//  horse -> rorse (replace 'h' with 'r')
//  rorse -> rose (remove 'r')
//  rose -> ros (remove 'e')
//  
//  Example 2:
//  
//  Input: word1 = "intention", word2 = "execution"
//  Output: 5
//  Explanation: 
//  intention -> inention (remove 't')
//  inention -> enention (replace 'i' with 'e')
//  enention -> exention (replace 'n' with 'x')
//  exention -> exection (replace 'n' with 'c')
//  exection -> execution (insert 'u')
//  
//   
//  Constraints:
//  
//  0 <= word1.length, word2.length <= 500
//  word1 and word2 consist of lowercase English letters.
//  
//  

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if(j == 0) {
                    dp[i][j] = i;
                } else if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }

        return dp[m][n];

    }
};

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> cache(n, vector<int>(m, INT_MAX));
        return helper(word1, word2, 0, 0, cache);
    }

    int helper(string &word1, string &word2, int i, int j, vector<vector<int>> &cache) {
        if (i == word1.size()) {
            return word2.size() - j;
        }

        if (j == word2.size()) {
            return word1.size() - i;
        }

        if (cache[i][j] != INT_MAX) {
            return cache[i][j];
        }

        if (word1[i] == word2[j]) {
            cache[i][j] = helper(word1, word2, i + 1, j + 1, cache);
        } else {
            int insert = helper(word1, word2, i, j + 1, cache) + 1;
            int remove = helper(word1, word2, i + 1, j, cache) + 1;
            int replace = helper(word1, word2, i + 1, j + 1, cache) + 1;

            cache[i][j] = min(min(insert, remove), replace);
        }

        return cache[i][j];
    }
};