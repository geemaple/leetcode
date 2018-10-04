//f[i][w] = max(f[i - 1][w], f[i - 1][w - A[i - 1]] + V[i - 1])

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        vector<int>table(m + 1, -1);
        table[0] = 0;
        
        for(auto i = 0; i < A.size(); ++i)
        {
            for(auto w = m + 1; w >= 0; --w)
            {
                int value = table[w];
                
                if (w - A[i] >= 0 && table[w - A[i]] != -1)
                {
                    value = max(value, table[w - A[i]] + V[i]);
                }
                table[w] = value;
            }
        }
        
        return *max_element(table.begin(), table.end());
    }
};