class Solution {
    
private:
    int findMin(vector<int> &nums)
    {
        int start = 0;
        int end = nums.size() - 1;
        
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] > nums[end])
            {
                start = mid;
            }
            else if(nums[mid] < nums[end])
            {
                end = mid;
            }
            else
            {
                end--;
            }
        }
        
        return nums[start] < nums[end] ? start : end;
    }
    
    void rotate(vector<int> &nums, int start, int end)
    {
        while(start <= end)
        {
            int tmp  = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            
            start++;
            end--;
        }
    }
    
public:
    /**
     * @param nums: An integer array
     * @return: nothing
     */
    void recoverRotatedSortedArray(vector<int> &nums) {
        // write your code here
        int index = findMin(nums);
        
        if (index == 0)
        {
            return;
        }
        
        int size = nums.size();
        
        rotate(nums, 0, index - 1);
        rotate(nums, index, size - 1);
        rotate(nums, 0 , size - 1);
    }
};