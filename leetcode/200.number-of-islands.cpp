class Solution {
private:
    unordered_set<int> visited;
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    bool in_bound(vector<vector<char>>& grid, int x, int y)
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }
    
    int convert(vector<vector<char>>& grid, int x, int y)
    {
        return x * grid[x].size() + y;
    }
    
    void bfs(vector<vector<char>>& grid, int x, int y)
    {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        
        while (!q.empty())
        {
            pair<int, int> tmp = q.front();
            q.pop();
            
            for (auto i = 0; i < 4; ++i)
            {                
                int new_x = tmp.first + directions[i][0];
                int new_y = tmp.second + directions[i][1];
                int point = convert(grid, new_x, new_y);
                if (in_bound(grid, new_x, new_y) && grid[new_x][new_y] == '1' && visited.count(point) == 0)
                {
                    visited.insert(point);
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int count = 0;
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '0')
                {
                    continue;
                }
                
                if (visited.count(convert(grid, i, j)) == 0)
                {
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        
        return count;
    }
};