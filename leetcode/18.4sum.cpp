class Solution {
private:
    void twoSum(vector<int>& nums, int first, int second, int target, vector<vector<int>> &result){
        
        int left = second + 1;
        int right = nums.size() - 1;
        
        while (left < right) {
            int candidate = nums[first] + nums[second] + nums[left] + nums[right];
            
            if (candidate < target)
            {
                left += 1;
            }
            else if (candidate > target)
            {
                right -= 1;
            }
            else
            {
                vector<int> answer;
                answer.push_back(nums[first]);
                answer.push_back(nums[second]);
                answer.push_back(nums[left]);
                answer.push_back(nums[right]);
                result.push_back(answer);
                
                while(left < right && nums[left + 1] == nums[left]){
                    left += 1;
                }
                
                while(left < right && nums[right - 1] == nums[right]){
                    right -= 1;
                }
                
                left += 1;
                right -= 1;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
        {
            vector<vector<int>>();
        }
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (auto j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                
                twoSum(nums, i, j, target, res);
            }
        }
        
        return res;
    }
};
