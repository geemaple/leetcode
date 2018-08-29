class Solution {
private:
    int partition(vector<int>& nums, int start, int end)
    {
        int k = rand() % (end - start + 1) + start;
        // exchange with the end
        int tmp = nums[k];
        nums[k] = nums[end];
        nums[end] = tmp;

        k = start;
        for (int i = start; i < end; ++i)
        {
            if (nums[i] < nums[end])
            {
                int tmp = nums[i];
                nums[i] = nums[k];
                nums[k] = tmp;
                k ++;
            }
        }

        // exchange kth the end
        tmp = nums[k];
        nums[k] = nums[end];
        nums[end] = tmp;
        
        return k;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int start = 0;
        int end = (int)nums.size() - 1;
        k = nums.size() - k;

        while(start < end)
        {
            int mid = partition(nums, start, end);
            if (mid < k)
            {   
                start = mid + 1;
            }
            else if (mid > k)
            {
                end = mid - 1;
            }
            else
            {
                break;
            }
        }

        return nums[k];
    }
};
