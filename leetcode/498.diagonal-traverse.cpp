class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        int n = (int)matrix.size();
        if (n == 0)
        {
            return vector<int>();
        }
        
        int m = (int)matrix[0].size();
        if (m == 0)
        {
            return vector<int>();
        }
        
        vector<int> res;
        bool upwards = false;
        int x = 0;
        int y = 0;
        
        for (auto i = 0; i < m * n; ++i)
        {
            res.push_back(matrix[x][y]);
            if ((x + y) % 2 == 0) //move up
            {
                if(y == m - 1)
                {
                    x += 1;
                }
                else if (x == 0)
                {
                    y += 1;
                }
                else
                {
                    x -= 1;
                    y += 1;
                }
            }
            else // moving down
            {
                if(x == n - 1)
                {
                    y += 1;
                }
                else if (y == 0)
                {
                    x += 1;
                }
                else
                {
                    x += 1;
                    y -= 1;
                }
            }
        }
        
        
        return res;
    }
};
