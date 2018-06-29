class Solution {
public:
    // sum[to jth] - sum[to ith] = subArray(from ith to jth)
    // O(N * LogN)
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        // previous ith sum
        int smallest = INT_MAX;
        vector<int> sums(nums.size() + 1, 0);
        for (auto i = 1; i < sums.size(); ++i)
        {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        
        for (auto i = 1; i < sums.size(); ++i) {
            int to_find = s + sums[i - 1];
            auto bound = lower_bound(sums.begin(), sums.end(), to_find);
            if (bound != sums.end()) {
                smallest = min(smallest, static_cast<int>(bound - (sums.begin() + i - 1)));
            }
        }
        
        return (smallest != INT_MAX)? smallest: 0;
    }
    
    // two-pointer  O(N)
    int minSubArrayLen2(int s, vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int smallest = INT_MAX;
        int sum = 0;
        int start = 0;
        for (auto end = 0; end < nums.size(); ++end)
        {
            sum += nums[end];
            while (sum >= s) {
                smallest = min(smallest, end - start + 1);
                sum -= nums[start];
                start += 1;
            }
        }
        
        return (smallest != INT_MAX)? smallest: 0;
    }
    
    // Brute force O(N ^ 2)
    int minSubArrayLen3(int s, vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int smallest = INT_MAX;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] >= s)
            {
                return 1;
            }
            
            int sum = nums[i];
            int count = 1;
            
            for (auto j = i + 1; j < nums.size(); ++j)
            {
                sum += nums[j];
                count += 1;
                if (sum >= s)
                {
                    smallest = min(smallest, count);
                    break;
                }
            }
        }
        
        return (smallest != INT_MAX)? smallest: 0;
    }
};
