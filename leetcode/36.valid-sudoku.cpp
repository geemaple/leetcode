class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row[9][9] = {0};
        int column[9][9] = {0};
        int block[9][9] = {0};
        
        for(auto i = 0; i < board.size(); ++i){
            for (auto j = 0; j < board[0].size(); ++j){
                
                if (board[i][j] == '.'){
                    continue;
                }
                
                int num = board[i][j] - '0' - 1; 
                int kth = i / 3 * 3 + j / 3;
                
                if (row[i][num] || column[j][num] || block[kth][num]){
                    return false;
                }
                
                
                row[i][num] = column[j][num] = block[kth][num] = 1;
            }
        }
        
        return true;
    }
};