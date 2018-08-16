class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int j = i + 1;
            
            while(j < nums.size() && nums[j] - nums[i] < k)
            {
                j++;
            }
            
            if (j < nums.size() && nums[j] - nums[i] == k)
            {
                ans += 1;
                
                // remove duplicate
                while(i + 1 < nums.size() && nums[i + 1] == nums[i])
                {
                    i++;
                }
            }
        }
        
        return ans;
    }
};