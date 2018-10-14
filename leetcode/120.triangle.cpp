//for each node f[parent] = min(f[left-child], f[right-child]) + val
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = (int)(triangle.size());
        vector<int> table(size, 0);
        
        // init
        for (auto j = 0; j < size; ++j)
        {
            table[j] = triangle[size - 1][j];
        }
        
        for(auto i = size - 2; i >= 0; --i)
        {
            for(auto j = 0; j <= i; ++j)
            {
                table[j] = min(table[j], table[j + 1]) + triangle[i][j];
            }
        }
        
        return table[0];
    }
};