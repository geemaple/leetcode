// f[i] = max(f[j] + 1) where nums[i] % nums[j] == 0
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return vector<int>();
        }
        
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> table(size, 1);
        vector<int> ans(size, -1);
        int index = 0;
        int longest = 1;
        
        for(auto i = 1; i < size; ++i)
        {
            for (auto j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && table[j] + 1 > table[i])
                {
                    table[i] = table[j] + 1;
                    ans[i] = j;
 
                }
            }
            
            if (table[i] > longest)
            {
                longest = table[i];
                index = i;
            }
        }
        
        vector<int> result;
        while(index != -1)
        {
            result.push_back(nums[index]);
            index = ans[index];
        }
        
        return result;
    }
};