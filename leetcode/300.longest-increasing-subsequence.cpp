// O(N * logN)
// when ever found bigger one 

// f(i) = max(1, table[j] + 1 if nums[i] > nums[j])
// O(N^2)
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if (nums.size() == 0){
            return 0;
        }
        
        int size = nums.size();
        vector<int> table(size, 0);
        table[0] = 1;
        
        for (auto i = 1; i < size; ++i)
        {
            int value = 1;
            for (auto j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    value = max(value, table[j] + 1);
                }
            }
            
            table[i] = value;
        }
        
        return *max_element(table.begin(), table.end());
    }
};