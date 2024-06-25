//  Tag: Binary Search on Answer, Binary Search
//  Time: O(N * logM + M * logN)
//  Space: O(1)
//  Ref: -
//  Note: Range

// Binary Search (M * logN + N * LogM)
class Solution {
private:
    bool checkRow(vector<vector<char>> &image, int row, int leftBound, int rightBound)
    {
        for(auto j = leftBound; j <= rightBound; ++j)
        {
            if (image[row][j] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    int searchTop(vector<vector<char>> &image, int x, int y)
    {
        int start = 0;
        int end = x;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid, 0, image[0].size() - 1))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        return checkRow(image, start, 0, image[0].size() - 1) ? start : end;
    }
    
    int searchBottom(vector<vector<char>> &image, int x, int y)
    {
        int start = x;
        int end = image.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (checkRow(image, mid, 0, image[0].size() - 1))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return checkRow(image, end, 0, image[0].size() - 1) ? end : start;
    }
    
    
    bool checkColomn(vector<vector<char>> &image, int col, int topBoundry, int bottomBoundry)
    {
        for(auto i = topBoundry; i <= bottomBoundry; ++i)
        {
            if (image[i][col] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    int searchLeft(vector<vector<char>> &image, int x, int y, int topBoundry, int bottomBoundry)
    {
        int start = 0;
        int end = y;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (checkColomn(image, mid, topBoundry, bottomBoundry))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        return checkColomn(image, start, topBoundry, bottomBoundry) ? start: end;
    }
    
    int searchRight(vector<vector<char>> &image, int x, int y, int topBoundry, int bottomBoundry)
    {
        int start = y;
        int end = image[0].size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (checkColomn(image, mid, topBoundry, bottomBoundry))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return checkColomn(image, end, topBoundry, bottomBoundry) ? end: start;
    }
    
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int top = searchTop(image, x, y);
        int bottom = searchBottom(image, x, y);
        
        int left = searchLeft(image, x, y, top, bottom);
        int right = searchRight(image, x, y, top, bottom);
        
        return (bottom - top + 1) * (right - left + 1);
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
