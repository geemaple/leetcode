class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)
        {
            return false;
        }
        
        int row = matrix.size();
        int column = matrix[0].size();
        if (column == 0)
        {
            return false;
        }
        
        // start from top right
        int x = 0;
        int y = column - 1;
        
        while (x < row && y >= 0) {
            
            if (matrix[x][y] == target)
            {
                return true;
            }
            
            if (matrix[x][y] > target)
            {
                y -= 1;
            }
            else
            {
                x += 1;
            }
        }
        
        return false;
    }
};
