class Solution {
private:
    int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    
    bool check(vector<vector<char>>& board, int x, int y)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[x].size());
    }
    
    int convert_point(vector<vector<char>>& board, int x, int y)
    {
        return x * board[x].size() + y;
    }
    
    void bfs(vector<vector<char>>& board, unordered_set<int> &visited, int x, int y)
    {
        
        if (board[x][y] != 'O')
        {
            visited.insert(convert_point(board, x, y));
            return;
        }
        

        int candidate = convert_point(board, x, y);
        if (visited.count(candidate) > 0)
        {
            return;
        }

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        visited.insert(convert_point(board, x, y));
        
        while(!q.empty())
        {
            pair<int, int> point = q.front();
            q.pop();
            
            for(auto i = 0; i < 4; ++i)
            {
                int new_x = point.first + directions[i][0];
                int new_y = point.second + directions[i][1];
                
                int candidate = convert_point(board, new_x, new_y);
                if (check(board, new_x, new_y) && visited.count(candidate) == 0 && board[new_x][new_y] == 'O')
                {
                    visited.insert(candidate);
                    q.push(make_pair(new_x, new_y));
                }
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        
        if (board.size() == 0 || board[0].size() == 0)
        {
            return;
        }
        
        unordered_set<int> visited;
        
        for (auto i = 0; i < board.size(); ++i)
        {
            bfs(board, visited, i, 0);
            bfs(board, visited, i, board[i].size() - 1);
        }
        
        for (auto j = 1; j < board[0].size() - 1; ++j)
        {
            bfs(board, visited, 0, j);
            bfs(board, visited, board.size() - 1, j);
        }
        
        for (auto i = 0; i < board.size(); ++i)
        {
            for (auto j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'O' && visited.count(convert_point(board, i, j)) == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};