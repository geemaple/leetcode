#define DIRECTIONS (8)
class Solution {
private:
    // clock wise
    int moveX[DIRECTIONS] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int moveY[DIRECTIONS] = {0, 1, 1, 1, 0, -1, -1, -1};
    
public:
    // BFS pair<int, int> is not hashable
    int minArea(vector<vector<char>>& image, int x, int y) {
        
        if (image.size() == 0)
        {
            return 0;
        }
        
        int top, bottom = x;
        int left, right = y;
        unordered_set<pair<int, int>> visted;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visted.insert(make_pair(x, y));
        
        while (!q.empty()) {
            pair<int, int> point = q.front();
            q.pop();
            
            // update area
            top = min(x, top);
            bottom = max(x, bottom);
            left = min(y, left);
            right = max(y, right);
            
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
