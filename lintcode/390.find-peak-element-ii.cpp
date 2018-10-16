class Solution {
private:
    bool isPeak(vector<vector<int>> &A, int x, int y)
    {
        return (A[x][y] > A[x - 1][y] && A[x][y] > A[x + 1][y] && A[x][y] > A[x][y - 1] && A[x][y] > A[x][y + 1]);
    }
    
    int findRowPeak(vector<vector<int>> &A, int row, int left, int right)
    {
        int res = left;
        for (auto j = left + 1; j <= right; ++j)
        {
            if (A[row][res] < A[row][j])
            {
                res = j;
            }
        }
        
        return res;
    }
    
    int findColPeak(vector<vector<int>> &A, int col, int top, int bottom)
    {
        int res = top;
        for (auto i = top + 1; i <= bottom; ++i)
        {
            if (A[res][col] < A[i][col])
            {
                res = i;
            }
        }
        
        return res;
    }
    
    void findPeak(vector<int> &res, vector<vector<int>> &A, int top, int left, int bottom, int right)
    {
        if (top + 1 >= bottom && left + 1 >= right)
        {
            int x = top;
            int y = left;
            
            if (A[top][right] > A[x][y]) {
                x = top;
                y = right;
            }
            
            if (A[bottom][left] > A[x][y]) {
                x = bottom;
                y = left;
            }
            
            if (A[bottom][right] > A[x][y]) {
                x = bottom;
                y = right;
            }
            
            res.push_back(x);
            res.push_back(y);
            return;
        }
        
        bool isHorizontal = (bottom - top + 1) >= (right - left + 1);
        
        if (isHorizontal)
        {
            int start = top;
            int end = bottom;
            
            int mid = start + (end - start) / 2;
            int max_y = findRowPeak(A, mid, left, right);
            
            if (isPeak(A, mid, max_y))
            {
                res.push_back(mid);
                res.push_back(max_y);
                return;
            }
            
            if (A[mid][max_y] < A[mid - 1][max_y])
            {
                findPeak(res, A, top, left, mid, right);
            }
            else
            {
                findPeak(res, A, mid, left, bottom, right);
            }
        }
        else
        {
            int start = left;
            int end = right;
            
            int mid = start + (end - start) / 2;
            int max_x = findColPeak(A, mid, top, bottom);
            if (isPeak(A, max_x, mid))
            {
                res.push_back(max_x);
                res.push_back(mid);
                return;
            }
            
            if (A[max_x][mid] < A[max_x][mid - 1])
            {
                findPeak(res, A, top, left, bottom, mid);
            }
            else
            {
                findPeak(res, A, top, mid, bottom, right);
            }
        }
    }
    
public:
    /*
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int>> &A) {
        // write your code here
        
        vector<int> res;
        findPeak(res, A, 0, 0, A.size() - 1, A[0].size() - 1);
        
        return res;
    }
};