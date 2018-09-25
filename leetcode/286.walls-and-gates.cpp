static int INF = INT_MAX;

class Solution {
    
private:
    int direcrtion[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    bool check(vector<vector<int>>& rooms, int x, int y)
    {
        return (x >=0 && x < rooms.size() && y >=0 && y < rooms[x].size());
    }
    
    int convert(vector<vector<int>>& rooms, int x, int y)
    {
        return x * rooms[x].size() + y;
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<pair<int, int>> q;
        
        // find all gates
        for(auto i = 0; i < rooms.size(); ++i)
        {
            for(auto j = 0; j < rooms[i].size(); ++j)
            {
                if (rooms[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                    visited.insert(convert(rooms, i, j));
                }
            }
        }
        
        // bfs
        int level = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                pair<int, int> top = q.front();
                q.pop();
                rooms[top.first][top.second] = level;
                
                for (auto j = 0; j < 4; ++j)
                {
                    int new_x = top.first + direcrtion[j][0];
                    int new_y = top.second + direcrtion[j][1];
                    
                    int point = convert(rooms, new_x, new_y);
                    if (check(rooms, new_x, new_y) && visited.count(point) == 0 && rooms[new_x][new_y] == INF)
                    {
                        visited.insert(point);
                        q.push(make_pair(new_x, new_y));
                    }
                }
            }
            
            level++;
        }
    }
};