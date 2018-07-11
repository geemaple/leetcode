class Solution {
private:
    int partition(vector<int>& nums, int start, int end){
        int index = rand() % (end - start + 1) + start;
        int tmp = nums[index];
        nums[index] = nums[end];
        nums[end] = tmp;
        
        int pos = start;
        for (auto i = start; i < end; ++i)
        {
            if (nums[i] <= nums[end])
            {
                int tmp = nums[pos];
                nums[pos] = nums[i];
                nums[i] = tmp;
                pos += 1;
            }
        }
        
        tmp = nums[pos];
        nums[pos] = nums[end];
        nums[end] = tmp;
        
        return pos;
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        int start = 0;
        int end = nums.size() - 1;
        k = nums.size() - k;
        while (start < end) {
            
            int pos = partition(nums, start, end);
            
            if (pos > k)
            {
                end = pos - 1;
            }
            else if(pos < k)
            {
                start = pos + 1;
            }
            else
            {
                break;
            }
        }
        
        return nums[k];
    }
};
