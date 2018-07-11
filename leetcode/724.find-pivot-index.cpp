class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int count = nums.size();
        vector<int> mem(count + 1, 0); // could use two variables instead
        for (auto i = 0; i < count; ++i)
        {
            mem[i + 1] = mem[i] + nums[i];
        }
        
        for (auto i = 0; i < count; ++i)
        {
            if (mem[i] - mem[0] == mem[count] - mem[i + 1])
            {
                return i;
            }
        }
        
        return -1;
    }
};