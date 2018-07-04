class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
        {
            return false;
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            //TODO: Tonight
        }
        
        if (nums[start] == target || nums[end] == target)
        {
            return true;
        }

        return false;
    }
};
