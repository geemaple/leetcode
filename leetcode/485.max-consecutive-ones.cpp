class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = 0;
        int res = 0;
        
        for(auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                size += 1;
            }
            else
            {
                res = max(res, size);
                size = 0;
            }
        }
        
        return max(res, size);
    }
};