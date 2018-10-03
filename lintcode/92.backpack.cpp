// f[i][w] = f[i - 1][w] or f[i - 1][w - A[i - 1]]
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        vector<bool> table(m + 1, false);
        table[0] = true;
        
        for (auto i = 0; i < A.size(); ++i)
        {
            for (auto w = m; w >= 0; --w)
            {
                bool value = table[w];
                if (w - A[i] >= 0)
                {
                    value = value || table[w - A[i]];
                }
                
                table[w] = value;
            }
        }
        
        int maxsize = 0;
        for (auto i = m + 1; i >= 0; --i)
        {
            if (table[i])
            {
                maxsize = i;
                break;
            }
        }
        
        return maxsize;
    }
};