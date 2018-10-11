class Solution {
    
private:
    bool isSufficient(vector<int> &L, int length, int nums)
    {
        if (length == 0)
        {
            return false;
        }
        
        int ans = 0;
        for (auto i = 0; i < L.size(); ++i)
        {
            ans += L[i] / length;
        }
        
        return ans >= nums;
    }
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    int woodCut(vector<int> &L, int k) {
        // write your code here
        if (L.size() == 0)
        {
            return 0;
        }
        
        int start = 0;
        int end = *max_element(L.begin(), L.end());
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            
            if (isSufficient(L, mid, k))
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return isSufficient(L, end, k) ? end : start;
    }
};
