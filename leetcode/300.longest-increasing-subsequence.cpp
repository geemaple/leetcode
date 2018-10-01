// O(N * logN)
// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> table;
        for(auto i = 0; i < nums.size(); ++i)
        {
            auto it = lower_bound(table.begin(), table.end(), nums[i]);
            if (it == table.end())
            {
                table.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }

        return table.size();
    }
};

// f(i) = max(1, f(j) + 1 if j < i and nums[j] < nums[i])
// O(N ^ 2)
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int m = nums.size();
        vector<int> table(m, 0);
        table[0] = 1;
        
        for(auto i = 1; i < m; ++i)
        {
            int value =  1;
            for(auto j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    value = max(value, table[j] + 1);
                }
            }
            table[i] = value;
        }
        
        return *max_element(table.begin(), table.end());
    }
};

