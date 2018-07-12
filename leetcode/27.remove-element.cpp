class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int size = 0;
        int k = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == val)
            {
                continue;
            }
            
            nums[k++] = nums[i];
            size += 1;
        }
        
        return size;
    }
};
