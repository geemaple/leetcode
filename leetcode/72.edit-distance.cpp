// f[i][j] = min(
//    f[i][j - 1] + 1,  
//    f[i - 1][j] + 1, 
//    f[i - 1][j - 1] + 1,  where s1[i - 1] != s2[j - 1]
//    f[i - 1][j - 1] where s1[i - 1] == s2[j - 1]
// )

// O(MN) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> table(m + 1, vector<int>(n + 1, INT_MAX));
        
        for (auto i = 0; i <= m; ++i)
        {
            for(auto j = 0; j <= n; ++j)
            {
                // init
                if (i == 0 || j == 0)
                {
                    table[i][j] = abs(i - j);
                    continue;
                }
                
                // function
                table[i][j] = min(table[i][j], table[i - 1][j] + 1); //delete
                table[i][j] = min(table[i][j], table[i][j - 1] + 1); //insert
                
                if (word1[i - 1] == word2[j - 1])
                {
                    table[i][j] = min(table[i][j], table[i - 1][j - 1]); // last equal
                }
                else
                {
                    table[i][j] = min(table[i][j], table[i - 1][j - 1] + 1); //replace
                }
            }
        }
        
        return table[m][n];
    }
};

// sliding array O(N) space
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int k = 2;
        vector<vector<int>> table(k, vector<int>(n + 1, 0));
        
        for (auto i = 0; i <= m; ++i)
        {
            for(auto j = 0; j <= n; ++j)
            {
                // init
                table[i % k][j] = INT_MAX;
                if (i == 0 || j == 0)
                {
                    table[i % k][j] = abs(i - j);
                    continue;
                }
                
                // function
                table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j] + 1); //delete
                table[i % k][j] = min(table[i % k][j], table[i % k][j - 1] + 1); //insert
                
                if (word1[i - 1] == word2[j - 1])
                {
                    table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j - 1]); // last equal
                }
                else
                {
                    table[i % k][j] = min(table[i % k][j], table[(i - 1) % k][j - 1] + 1); //replace
                }
            }
        }
        
        return table[m % k][n];
    }
};