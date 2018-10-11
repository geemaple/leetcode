class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[end])
            {
                start = mid;
            }
            else if (nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                end--;
            }
        }
        
        return min(nums[start], nums[end]);
    }
};
