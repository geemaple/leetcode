class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();

        // top-right
        int i = 0;
        int j = n - 1;

        while(i < m && j >= 0)
        {
            if (matrix[i][j] > target)
            {
                j --;
            }
            else if (matrix[i][j] < target)
            {
                i++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};
