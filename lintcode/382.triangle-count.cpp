class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        int res = 0;
        sort(S.begin(), S.end());
        
        for (auto i = (int)(S.size()) - 1; i >=0; --i)
        {
            res += count(S, i);
        }
        
        return res;
    }
    
    int count(vector<int> &nums, int longestIndex)
    {
        int res = 0;
        int start = 0;
        int end = longestIndex - 1;
        
        while (start < end)
        {
            if (nums[start] + nums[end] > nums[longestIndex])
            {
                res += end - start;
                end --;
            }
            else
            {
                start ++;
            }
        }
        
        return res;
    }
};