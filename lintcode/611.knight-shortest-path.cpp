/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {

private:
    vector<vector<int>> directions = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

    bool in_bound(vector<vector<bool>> &grid, int x, int y)
    {
        return  x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size();
    }

public:
    /**
     * @param grid: a chessboard included 0 (false) and 1 (true)
     * @param source: a point
     * @param destination: a point
     * @return: the shortest path 
     */
    int shortestPath(vector<vector<bool>> &grid, Point &source, Point &destination) {
        // write your code here

        queue<pair<int, int>> q;
        q.push(make_pair(source.x, source.y));
        grid[source.x][source.y] = true;

        int steps = 0;

        while(!q.empty())
        {
            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                pair<int, int> tmp = q.front();
                q.pop();

                if (tmp.first == destination.x && tmp.second == destination.y)
                {
                    return steps;
                }

                for (auto i = 0; i < 8; i++)
                {
                    int new_x = tmp.first + directions[i][0];
                    int new_y = tmp.second + directions[i][1];
                    if (in_bound(grid, new_x, new_y) && grid[new_x][new_y] == 0)
                    {
                        q.push(make_pair(new_x, new_y));
                        grid[new_x][new_y] = true;
                    }
                }
            }
    
            steps++;
        }

        return -1;
    }
};