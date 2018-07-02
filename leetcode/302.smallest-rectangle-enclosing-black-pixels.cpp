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

class Solution {
private:
    // clock wise
    int moveX[DIRECTIONS] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int moveY[DIRECTIONS] = {0, 1, 1, 1, 0, -1, -1, -1};
    
public:
    // BFS O(M * N)
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
