class Solution {
private:
    
    int searchClosest(vector<int>& nums, int target)
    {
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
                return mid;
            }
        }
        
        return (abs(nums[start] - target) < abs(nums[end] - target)) ? start: end;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int size = arr.size();
        int index = searchClosest(arr, x);
        
        int start = index;
        int end = index;
        for (auto i = 1; i < k; ++i)
        {
            if (start - 1 < 0 && end + 1 >= size)
            {
                break;
            }
            
            if (start - 1 >= 0 && end + 1 < size)
            {
                if (abs(arr[start - 1] - x) <= abs(arr[end + 1] - x))
                {
                    start--;
                }
                else
                {
                    end++;
                }
            }
            else if (start - 1 >= 0)
            {
                start--;
            }
            else
            {
                end++;
            }
        }
        
        vector<int> result;
        for(auto i = start; i <= end; ++i)
        {
            result.push_back(arr[i]);
        }
        
        return result;
    }
};
