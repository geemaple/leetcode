class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }

        int i = 0;
        int res = 1;
        for(auto j = 1; j < nums.size(); ++j)
        {
            if(nums[j] > nums[j - 1])
            {
                res = max(res, j - i + 1);
            }
            else
            {
                i = j;
            }
        }

        return res;
    }
};
