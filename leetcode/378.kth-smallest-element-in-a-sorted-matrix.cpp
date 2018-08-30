class Solution {

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        struct Tuple{
            int x, y, val;
            Tuple(int _x, int _y, int _val): x(_x), y(_y), val(_val){}
        };

        auto cmp = [](const Tuple &left, const Tuple& right)
        {
            return left.val > right.val;
        };

        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();

        for(int i = 0; i < m; ++i)
        {
            pq.push(Tuple(i, 0, matrix[i][0]));
        }

        
        for (int i = 0; i < k - 1; ++i)
        {
            Tuple t = pq.top();
            pq.pop();

            if (t.y + 1 < n)
            {
                pq.push(Tuple(t.x, t.y + 1, matrix[t.x][t.y + 1]));
            }
        }

        return pq.top().val;
    }
};