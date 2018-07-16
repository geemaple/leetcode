// Binary Search (M * logN + N * LogM)
class Solution {
    int getLeft(vector<vector<char>>& image, int startX, int endX, int startY, int endY)
    {
        int start = startX;
        int end = endX;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkColumn(image, mid, startY, endY))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (checkColumn(image, start, startY, endY))
        {
            return start;
        }
        
        return end;
    }
    
    int getRight(vector<vector<char>>& image, int startX, int endX, int startY, int endY)
    {
        int start = startX;
        int end = endX;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkColumn(image, mid, startY, endY))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if (checkColumn(image, end, startY, endY))
        {
            return end;
        }
        
        return start;
    }
    
    int getTop(vector<vector<char>>& image, int startX, int endX, int startY, int endY)
    {
        int start = startY;
        int end = endY;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid, startX, endX))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (checkRow(image, start, startX, endX))
        {
            return start;
        }
        
        return end;
    }
    
    int getBottom(vector<vector<char>>& image, int startX, int endX, int startY, int endY)
    {
        int start = startY;
        int end = endY;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid, startX, endX))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if (checkRow(image, end, startX, endX))
        {
            return end;
        }
        
        return start;
    }
    
    bool checkColumn(vector<vector<char>>& image, int column, int start, int end)
    {
        for (auto i = start; i <= end; ++i)
        {
            if (image[i][column] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool checkRow(vector<vector<char>>& image, int row, int start, int end)
    {
        for (auto i = start; i <= end; ++i)
        {
            if (image[row][i] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left = getLeft(image, 0, y, 0, (int)image.size() - 1);
        int right = getRight(image, y, (int)image[0].size() - 1, 0, (int)image.size() - 1);
        int top = getTop(image, left, right, 0, x);
        int bottom = getBottom(image, left, right, x, (int)image.size() - 1);
        
        return (right - left + 1) * (bottom - top + 1);
    }
};

#define DIRECTIONS (8)
struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const
    {
        // Modified Bernstein hash
        // http://eternallyconfuzzled.com/tuts/algorithms/jsw_tut_hashing.aspx
        return ( 33 * pair.first ) ^ pair.second;
    }
};

// BFS O(M * N)
class Solution2 {
private:
    // clock wise
    int moveX[DIRECTIONS] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int moveY[DIRECTIONS] = {0, 1, 1, 1, 0, -1, -1, -1};
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        if (image.size() == 0)
        {
            return 0;
        }
        
        int top = x, bottom = x;
        int left = y, right = y;
        unordered_set<pair<int, int>, pair_hash> visted;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visted.insert(make_pair(x, y));
        
        while (!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();
            
            // update area
            top = min(point.first, top);
            bottom = max(point.first, bottom);
            left = min(point.second, left);
            right = max(point.second, right);
            
            for (auto i = 0; i < DIRECTIONS; ++i)
            {
                pair<int, int>moveTo = make_pair(point.first + moveX[i], point.second + moveY[i]);
                
                // check visted
                if (visted.count(moveTo) > 0)
                {
                    continue;
                }
                
                // boudry check
                if (moveTo.first < 0 || moveTo.first >= image.size() || moveTo.second < 0 || moveTo.second >= image[0].size())
                {
                    continue;
                }
                
                if (image[moveTo.first][moveTo.second] == '1')
                {
                    visted.insert(moveTo);
                    q.push(moveTo);
                }
            }
        }
        
        return (right - left + 1) * (bottom - top + 1);
    }
};
