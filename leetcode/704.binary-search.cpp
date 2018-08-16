class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = (int)(nums.size() - 1);

        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target)
            {
                start = mid;
            }
            else if (nums[mid] > target)
            {
                end = mid;
            }
            else
            {
                return mid;
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
};
