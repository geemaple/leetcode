class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0)
        {
            return false;
        }
        
        int row = (int)matrix.size();
        int column = (int)matrix[0].size();
        
        if (column == 0)
        {
            return false;
        }
        
        int start = 0;
        int end = row * column - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (matrix[mid / column][mid % column] > target)
            {
                end = mid;
            }
            else if (matrix[mid / column][mid % column] < target)
            {
                start = mid;
            }
            else
            {
                return true;
            }
        }
        
        if (matrix[start / column][start % column] == target || matrix[end / column][end % column] == target)
        {
            return true;
        }
        
        return false;
    }
};
