class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        
        int maxIndex = 0;
        for (auto i = 1; i < nums.size(); ++i)
        {
            if (nums[maxIndex] < nums[i])
            {
                maxIndex = i;
            }
        }
        
        for(auto i = 0; i < nums.size(); ++i)
        {
            if (i != maxIndex && nums[i] * 2 > nums[maxIndex])
            {
                return -1;
            }
        }
        
        return maxIndex;
    }
};