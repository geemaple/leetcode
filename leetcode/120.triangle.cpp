class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        // width and height is the same
        int size = (int)triangle.size();
        vector<int> table(size, 0);
        
        // initialization
        for (auto i = 0; i < triangle[size - 1].size(); ++i)
        {
            table[i] = triangle[size - 1][i];
        }
        
        //from bottom to up
        for (auto i = size - 2; i >= 0; --i)
        {
            for (auto j = 0; j < triangle[i].size(); ++j)
            {
                table[j] = min(table[j], table[j + 1]) + triangle[i][j];
            }
        }
        
        return table[0];
    }
};
