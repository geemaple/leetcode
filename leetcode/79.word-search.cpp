class Solution {
private:

    int directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

    int convert_point(vector<vector<char>>& board, int x, int y)
    {
        return x * board[0].size() + y;
    }

    bool check_in_board(vector<vector<char>>& board, int x, int y)
    {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[x].size());
    }

    bool dfs_search(vector<vector<char>>& board, int x, int y, unordered_set<int>& visted, string &word, int index)
    {
        if (board[x][y] != word[index])
        {
            return false;
        }

        if (index == word.size() - 1)
        {
            return true;
        }

        int point = convert_point(board, x, y);
        visted.insert(point);

        for (auto it: directions)
        {
            int new_x = x + it[0];
            int new_y = y + it[1];
            int new_point = convert_point(board, new_x, new_y);
            if (check_in_board(board, new_x, new_y) && visted.count(new_point) == 0)
            {
                if(dfs_search(board, new_x, new_y, visted, word, index + 1))
                {
                    return true;
                }
            }
        }

        visted.erase(point);
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        unordered_set<int> visted;
       
        for (int i = 0; i < board.size(); ++i)
        {
            vector<char> row = board[i];
            for (int j = 0; j < row.size(); ++j)
            {
                bool result = dfs_search(board, i, j, visted, word, 0);
                if (result)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
