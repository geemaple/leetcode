// f[i][j] = min(f[i - 1][k] + |j - A[i - 1]|) where 1 <= K <= 100, | K - j | <= target

class Solution {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
        
        int size = A.size();
        vector<vector<int>> table(size + 1, vector<int>(100 + 1, INT_MAX));
        
        for (auto i = 1; i <= 100; ++i)
        {
            table[1][i] = abs(A[0] - i);
        }
        
        for (auto i = 2; i <= size; ++i)
        {
            for(auto j = 1; j <= 100; ++j)
            {
                int value = INT_MAX;
                
                for (auto k = j - target; k <= j + target; ++k)
                {
                    if (k < 1 || k > 100 || table[i - 1][k] == INT_MAX)
                    {
                        continue;
                    }
                    
                    value = min(value, table[i - 1][k] + abs(j - A[i - 1]));
                }
                
                table[i][j] = value;
            }
        }
        
        
        return *min_element(table[size].begin(), table[size].end());
    }
};