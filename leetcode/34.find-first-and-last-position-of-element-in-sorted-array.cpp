class Solution {

private:
    int searchHead(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }

        int start = 0;
        int end = nums.size() - 1;

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else if (nums[mid] < target)
            {
                start = mid;
            }
            else
            {
                end = mid;
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

    int searchTail(vector<int>& nums, int target)
    {
        if (nums.size() == 0)
        {
            return -1;
        }
        
        int start = 0;
        int end = nums.size() - 1;

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] > target)
            {
                end = mid;
            }
            else if (nums[mid] < target)
            {
                start = mid;
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        res.push_back(searchHead(nums, target));
        res.push_back(searchTail(nums, target));

        return res;   
    }
};
