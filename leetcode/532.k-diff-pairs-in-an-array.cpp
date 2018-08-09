class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right)
        {
            while (left < right && nums[right] - nums[left] >= k)
            {
                if (nums[right] - nums[left] == k)
                {
                    res++;
                    while(left + 1 < nums.size() && nums[left + 1] == nums[left])
                    {
                        left++;
                    }
                }

                left++;
            }

            right = max(left, right);
        }

        return res;
    }
};
