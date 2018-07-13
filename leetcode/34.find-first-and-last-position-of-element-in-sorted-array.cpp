class Solution {
private:
    int findFisrt(vector<int>& nums, int target)
    {
        int start = 0;
        int end = (int)nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] >= target)
            {
                end = mid;
            }
            else
            {
                start = mid;
            }
            
        }
        
        if (nums[start] == target)
        {
            return start;
        }
        
        if (nums[end] == target)
        {
            return end;
        }
        
        return -1;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int start = 0;
        int end = (int)nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] <= target)
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
            
        }
        
        if (nums[end] == target)
        {
            return end;
        }
        
        if (nums[start] == target)
        {
            return start;
        }
        
        return -1;
    }
    
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = findFisrt(nums, target);
        int last = findLast(nums, target);
        vector<int> res = {start, last};
        return res;
    }
};
