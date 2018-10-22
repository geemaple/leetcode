class Solution {
    
private:
    vector<vector<int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    
    bool in_bound(vector<vector<int>> &grid, int x, int y)
    {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }
    
    int convert(vector<vector<int>> &grid, int x, int y)
    {
        return x * grid[x].size() + y;
    }
    
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here
        
        int peopel_count = 0;
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        
        for (auto i = 0; i < grid.size(); ++i)
        {
            for (auto j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == 0)
                {
                    peopel_count++;
                    continue;
                }
                
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    visited.insert(convert(grid, i, j));
                }
            }
        }
        
        int days = 0;
        while(!q.empty() && peopel_count > 0)
        {
            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                pair<int, int>tmp = q.front();
                q.pop();
                
                for (auto i = 0; i < 4; ++i)
                {
                    int new_x = tmp.first + directions[i][0];
                    int new_y = tmp.second + directions[i][1];
                    int point = convert(grid, new_x, new_y);
                    
                    if (in_bound(grid, new_x, new_y) && grid[new_x][new_y] == 0 && visited.count(point) == 0)
                    {
                        visited.insert(point);
                        q.push(make_pair(new_x, new_y));
                        grid[new_x][new_y] = 1;
                        peopel_count--;
                    }
                }
            }
        
            days++;
        }
        
        return peopel_count == 0 ? days : -1;
    }
};