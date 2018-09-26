class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        if (A.size() == 0 || B.size() == 0)
        {
            return vector<vector<int>>();
        }
        
        vector<vector<pair<int, int>>> sparseB(B.size(), vector<pair<int, int>>());

        for (auto i = 0; i < B.size(); ++i)
        {
            for (auto j = 0; j < B[i].size(); ++j)
            {
                if (B[i][j] != 0){
                    sparseB[i].push_back(make_pair(j, B[i][j]));
                }
            }
        }

        int m = A.size();
        int n = B[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto k = 0; k < A[i].size(); ++k)
            {
                if (A[i][k] != 0){
                    for (auto p = 0; p < sparseB[k].size(); ++p)
                    {
                        int j = sparseB[k][p].first;
                        int val = sparseB[k][p].second;
                        
                        res[i][j] += A[i][k] * val;
                    }
                }
            }
        }

        
        return res;
    }
};

class Solution2 {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        if (A.size() == 0 || B.size() == 0)
        {
            return vector<vector<int>>();
        }
        
        int m = A.size();
        int n = B[0].size();
        
        int t = A[0].size();
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                for(auto k = 0; k < t; ++k)
                {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return res;
    }
};