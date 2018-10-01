// f(k)(i) = min(max(f(k - 1)(j), rest) where 0 <= j <= i)
// O(K * N^2)
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) {
        // write your code here
        if (pages.size() == 0)
        {
            return 0;
        }
        
        int m = pages.size();
        if (k > m)
        {
            k = m;
        }
        
        vector<vector<int>> table(k + 1, vector<int>(m + 1, INT_MAX));
        table[0][0] = 0;
        
        for (auto t = 1; t <= k; ++t)
        {
            table[t][0] = 0;
            
            for (auto i = 1; i <=m; ++i)
            {
                int value = INT_MAX;
                int rest = 0;
                for (auto j = i; j >= 0; j--){
                    int time = max(table[t - 1][j], rest);
                    value = min(value, time);
                    if (j - 1 >= 0)
                    {
                        rest += pages[j - 1];
                    }
                }
                
                table[t][i] = value;
            }
        }
        
        return table[k][m];
    }
};