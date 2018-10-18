//f[i] = max(f[i - 1] + nums[i], nums[i])  array ends with ith maximum subarray
// DP
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int m = nums.size();
        
        vector<int> table(m, 0);
        table[0] = nums[0];
        int largest = nums[0];
        
        for (auto i = 1; i < m; ++i)
        {
            table[i] = max(table[i - 1] + nums[i], nums[i]);
            largest = max(largest, table[i]);
        }
        
        return largest;
    }
};

// prefix-sum
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sumJ = 0;
        int sumI = 0;
        int largest = INT_MIN;
        
        // sub[i+1: j] = sum[:j] - sum[:i]
        for (auto i = 0; i < nums.size(); ++i)
        {
            sumJ += nums[i];
            largest = max(largest, sumJ - sumI);
            sumI = min(sumI, sumJ);
        }
        
        return largest;
    }
};