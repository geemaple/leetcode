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
public:
    void sortColors(vector<int>& nums) {
        
        int start = 0;
        int end = nums.size() - 1;
        int index = 0;
        
        while (index <= end) {
            
            if (nums[index] < 1)
            {
                int tmp = nums[index];
                nums[index] = nums[start];
                nums[start] = tmp;
                start += 1;
            }
            else if(nums[index] > 1)
            {
                int tmp = nums[index];
                nums[index] = nums[end];
                nums[end] = tmp;
                end -= 1;
                continue;
            }
            
            index += 1;
        }
    }
};
