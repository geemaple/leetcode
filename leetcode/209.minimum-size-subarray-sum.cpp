// two-pointer  O(N)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int res = INT_MAX;
        for (auto i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            while (sum >= s) {
                res = min(res, i - start + 1);
                sum -= nums[start];
                start += 1;
            }
        }
        
        return res == INT_MAX ? 0 : res;
    }
};

class Solution2 {
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
};