class Solution {
public:
    /*
     * @param A: An integer array.
     * @return: nothing
     */
    void rerange(vector<int> &A) {
        // write your code here
        
        int k = 0;
        for (auto i = 0; i < A.size(); ++i)
        {
            if (A[i] < 0)
            {
                int tmp = A[k];
                A[k] = A[i];
                A[i] = tmp;
                k++;
            }
        }
        
        int negCount = k;
        int posCount = A.size() - k;
        
        bool isPos = posCount > negCount;
        
        for (auto i = 0; i < A.size(); ++i)
        {
            if ((isPos && A[i] < 0) || (!isPos && A[i] > 0))
            {
                int tmp = A[k];
                A[k] = A[i];
                A[i] = tmp;
                k++;
            }
            
            isPos = !isPos;
        }
    }
};