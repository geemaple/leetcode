class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int result = nums[0] + nums[1] + nums[3];
        sort(nums.begin(), nums.end());
    
        for (auto i = 0; i < nums.size(); ++i)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int tmp = nums[i] + nums[left] + nums[right];
                if (abs(target - result) > abs(target - tmp))
                {
                    result = tmp;
                }

                if (tmp < target)
                {
                    left ++;
                }
                else if(tmp > target)
                {
                    right --;
                }
                else
                {
                    break;
                }
            }
        }
        
        return result;
    }
};
