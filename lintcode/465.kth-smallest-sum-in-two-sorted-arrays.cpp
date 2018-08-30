class Solution {
public:
    /**
     * @param A: an integer arrays sorted in ascending order
     * @param B: an integer arrays sorted in ascending order
     * @param k: An integer
     * @return: An integer
     */
    int kthSmallestSum(vector<int> &A, vector<int> &B, int k) {
        // write your code here
        
        struct Tuple{
            int x, y, val;
            Tuple(int _x, int _y, int _val): x(_x), y(_y), val(_val){}
        };
        
        auto cmp = [](const Tuple& left, const Tuple& right)
        {
            return left.val > right.val;
        };
        
        priority_queue<Tuple, vector<Tuple>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < B.size(); ++i)
        {
            pq.push(Tuple(i, 0, B[i] + A[0]));
        }
        
        for (int i = 0; i < k - 1; ++i)
        {
            Tuple t = pq.top();
            pq.pop();
            
            if (t.y + 1 < A.size())
            {
                pq.push(Tuple(t.x, t.y + 1, B[t.x] + A[t.y + 1]));
            }
        }
        
        return pq.top().val;
    }
};