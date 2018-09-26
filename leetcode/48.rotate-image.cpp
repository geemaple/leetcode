// m row X n col
// Quadrant 1 | Quadrant 2
// --------------------->
// Quadrant 4 | Quadrant 3
// Q1: (x, y)
// Q2: (y, m - 1 - x)
// Q3: (m - 1 - x, n - 1 - y)
// Q4: (n - 1 - y, x) in Q4

// rotate +90 mirror up and down, and swich x and y
// rotate -90 mirror left and right, and switch x and y

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
        {
            return;
        }

        int up = 0;
        int down = matrix.size() - 1;
        //mirror up and down
        while(up < down)
        {
            for (auto j = 0; j < matrix[0].size(); ++j)
            {
                int tmp = matrix[up][j];
                matrix[up][j] = matrix[down][j];
                matrix[down][j] = tmp;
            }
            up++;
            down--;
        }

        // switch x and y
        for (auto i = 0; i < matrix.size(); ++i)
        {
            for (auto j = i + 1; j < matrix[i].size(); ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
