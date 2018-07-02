class Solution {
private:
    int headBinarySearch(vector<int>& nums, int target){
        
        int start = 0;
        int end = nums.size() - 1;
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
    
    int tailBinarySearch(vector<int>& nums, int target){
        
        int start = 0;
        int end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                start = mid;
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
    // binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        
        if (nums.size() == 0)
        {
            return vector<int>{-1, -1};
        }
        
        int start = headBinarySearch(nums, target);
        int end = tailBinarySearch(nums, target);
        
        return vector<int>{start, end};
    }
};
