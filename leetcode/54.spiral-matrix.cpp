static int xDirections[4] = {0, 1, 0, -1};
static int yDirections[4] = {1, 0, -1, 0};
static int shrinkBound[4] = {1, -1, -1, 1};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = (int)matrix.size();
        if (n == 0)
        {
            return vector<int>();
        }
        
        int m = (int)matrix[0].size();
        vector<int> res;
        int bounds[4] = {0, m - 1, n - 1, 0}; //top right, bottom left
        
        int x = 0;
        int y = 0;
        res.push_back(matrix[x][y]);
        
        while (bounds[3] <= bounds[1] && bounds[0] <= bounds[2]) {
            for (auto i = 0; i < 4; ++i)
            {
                while (x + xDirections[i] >= bounds[0] && x + xDirections[i] <= bounds[2] && y + yDirections[i] >= bounds[3] && y + yDirections[i] <= bounds[1]) {
                    x = x + xDirections[i];
                    y = y + yDirections[i];
                    
                    res.push_back(matrix[x][y]);
                }
                
                bounds[i] += shrinkBound[i];
            }
        }
        
        return res;
    }
};
