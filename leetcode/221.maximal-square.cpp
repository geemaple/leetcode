class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> table(m , vector<int>(n, 0));
        int result = 0;
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i][j] = matrix[i][j];
                }
                else if (matrix[i][j] == 1)
                {
                    int value = min(table[i - 1][j], table[i][j - 1]);
                    value = min(value, table[i - 1][j - 1]);
                    
                    table[i][j] = 1 + value;
                }
                
                result = max(result, table[i][j]);
            }
        }
        
        return result * result;
    }
};