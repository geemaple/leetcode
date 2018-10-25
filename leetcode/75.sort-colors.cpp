// counting sort
static const int number_of_colors = 3;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countings[number_of_colors] = {0};
        vector<int> tmp(nums.size(), 0);
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            countings[nums[i]] += 1;
        }
        
        for (auto i = 1; i < number_of_colors; ++i)
        {
            countings[i] += countings[i - 1];
        }
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            int count = countings[nums[i]];
            tmp[count - 1] = nums[i];
            countings[nums[i]] -= 1;
        }
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            nums[i] = tmp[i];
        }
    }
};

class Solution2 {
private:
    void swap(vector<int>& nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp; 
    }
    
public:
    void sortColors(vector<int>& nums) {
        int k = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums, k, i);
                k ++;
            }
        }
        
        for (auto i = k; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                swap(nums, k, i);
                k ++;
            }
        }
        
    }
};
