class Solution {
private:
    int partition(vector<int>& nums, int start, int end){
        int select = start + rand() % (end - start + 1);
        int tmp = nums[select];
        nums[select] = nums[end];
        nums[end] = tmp;
        
        int k = start;
        for (auto i = start; i < end; ++i)
        {
            if (nums[i] <= nums[end])
            {
                int tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
                k += 1;
            }
        }
        
        tmp = nums[k];
        nums[k] = nums[end];
        nums[end] = tmp;
        
        return k;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int start = 0;
        int end = int(nums.size() - 1);
        k = int(nums.size() - k);
        
        while(start < end){
            
            int pos = partition(nums, start, end);
            if (pos == k)
            {
                break;
            }
            else if(pos > k)
            {
                end = pos - 1;
            }
            else
            {
                start = pos + 1;
            }
        }
        
        return nums[k];
    }
};
