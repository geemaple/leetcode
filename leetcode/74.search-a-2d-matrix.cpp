class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // write your code here
        if (matrix.size() == 0 or matrix[0].size() == 0)
        {
            return false;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int start = 0;
        int end = m * n - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            int val = matrix[mid / n][mid % n];
            
            if (val > target)
            {
                end = mid;
            }
            else if (val < target)
            {
                start = mid;
            }
            else
            {
                return true;
            }
        }
        
        return (matrix[start / n][start % n] == target || matrix[end / n][end % n] == target);
    }
};
