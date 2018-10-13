//f[i][j][t] = f[i - 1][j][t] + f[i - 1][j - 1][t - A[i - 1]]
class Solution {
public:
    /**
     * @param A: An integer array
     * @param k: A positive integer (k <= length(A))
     * @param target: An integer
     * @return: An integera
     */
    int kSum(vector<int> &A, int k, int target) {
        // write your code here
        
        int size = A.size();
        vector<vector<vector<int>>>table(size + 1, vector<vector<int>>(k + 1, vector<int>(target + 1, 0)));
        
        table[0][0][0] = 1;
        
        for(auto i = 1; i <= size; ++i)
        {
            for(auto j = 0; j <= k; ++j)
            {
                for(auto t = 0; t <= target; ++t)
                {
                    table[i][j][t] += table[i - 1][j][t];
                    
                    if(j - 1 >= 0 && t - A[i - 1] >= 0)
                    {
                        table[i][j][t] += table[i - 1][j - 1][t - A[i - 1]];
                    }
                }
            }
        }
        
        return table[size][k][target];
    }
};