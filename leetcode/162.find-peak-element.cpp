class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while (start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[mid - 1])
            {
                start = mid;
            }
            else
            {
                end = mid;
            }
        }
        
        return nums[start] > nums[end] ? start : end;
    }
};