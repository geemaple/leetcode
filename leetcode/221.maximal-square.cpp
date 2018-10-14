//f[i][j] = (min(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]) + 1) if matrix[i][j] == 0 else 0
// without space optimized runtime beats 98%
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
                    table[i][j] = matrix[i][j] == '1' ? 1 : 0;
                }
                else if (matrix[i][j] == '1')
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

// space optimized to O(N) runtime beats 43%
class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        
        int k = 2;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> table(k , vector<int>(n, 0));
        int result = 0;
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i % k][j] = matrix[i][j] == '1' ? 1: 0;
                }
                else if (matrix[i][j] == '1')
                {
                    int value = min(table[(i - 1) % k][j], table[i % k][j - 1]);
                    value = min(value, table[(i - 1) % k][j - 1]);
                    
                    table[i % k][j] = 1 + value;
                }
                else // this is important when using circular array, this increase runtime
                {
                    table[i % k][j] = 0;
                }
                
                result = max(result, table[i % k][j]);
            }
        }
        
        return result * result;
    }
};