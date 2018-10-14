// f[i] = max(f[i - 1], f[i - 2] + A[i - 1])

class Solution {

private:
    int robHouse(vector<int> &nums, int start, int end)
    {
        int size = end - start + 1;
        if (size <= 0) 
        {
            return 0;
        }
        
        int k = 2;
        vector<int> table(k, 0);
  
        table[0] = 0;
        table[1] = nums[start];
        
        for (auto i = 2; i <= size; ++i)
        {
            table[i % k] = max(table[(i - 1 + k) % k], table[(i - 2 + k) % k] + nums[start + i - 1]);
        }
        
        return table[size % k];
    }

public:
    int rob(vector<int>& nums) {
        // write your code here
        if (nums.size() == 0)
        {
            return 0;
        }
        
        int size = nums.size();
        
        return max(nums[0] + robHouse(nums, 2, size - 2), robHouse(nums, 1, size - 1));
    }
};