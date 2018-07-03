// Binary Search (M * logN + N * LogM)
class Solution {
private:
    bool columnHasBlack(vector<vector<char>>& image, int col){
        for (auto i = 0; i < image.size(); ++i)
        {
            if (image[i][col] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    bool rowHasBlack(vector<vector<char>>& image, int row){
        for (auto i = 0; i < image[row].size(); ++i)
        {
            if (image[row][i] == '1')
            {
                return true;
            }
        }
        
        return false;
    }
    
    int searchLeft(vector<vector<char>>& image, int start, int end){
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (columnHasBlack(image, mid))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (columnHasBlack(image, start))
        {
            return start;
        }
        
        return end;
    }
    
    int searchRight(vector<vector<char>>& image, int start, int end){
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (columnHasBlack(image, mid))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if (columnHasBlack(image, end))
        {
            return end;
        }
        
        return start;
    }
    
    int searchTop(vector<vector<char>>& image, int start, int end){
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (rowHasBlack(image, mid))
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
        }
        
        if (rowHasBlack(image, start))
        {
            return start;
        }
        
        return end;
    }
    
    int searchBottom(vector<vector<char>>& image, int start, int end){
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (rowHasBlack(image, mid))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        if (rowHasBlack(image, end))
        {
            return end;
        }
        
        return start;
    }
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        if (image.size() == 0)
        {
            return 0;
        }
        
        int row = (int)image.size();
        int column = (int)image[0].size();
        
        int left = searchLeft(image, 0, y);
        int right = searchRight(image, y, column - 1);
        
        int top = searchTop(image, 0, x);
        int bottom = searchBottom(image, x, row - 1);
        
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
