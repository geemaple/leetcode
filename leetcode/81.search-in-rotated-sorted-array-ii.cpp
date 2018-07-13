class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
        {
            return false;
        }
        
        int start = 0;
        int end = (int)nums.size() - 1;
        
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target)
            {
                return true;
            }
            
            if (nums[mid] < nums[end])
            {
                if (target > nums[mid] && target <= nums[end])
                {
                    start = mid;
                }
                else
                {
                    end = mid;
                }
            }
            else if (nums[mid] > nums[end])
            {
                if (target >= nums[start] && target < nums[mid])
                {
                    end = mid;
                }
                else
                {
                    start = mid;
                }
            }
            else
            {
                end -= 1;
            }
        }
        
        if (nums[start] == target || nums[end] == target)
        {
            return true;
        }
        
        return false;
    }
};
