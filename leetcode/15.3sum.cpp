class Solution {
private:
    void twoSum(vector<int>& nums, int start, int first, vector<vector<int>> &res){
        int left =  start + 1;
        int right = nums.size() - 1;
        
        while(left < right){
            int candidate = first + nums[left] + nums[right];
            if (candidate > 0)
            {
                right -= 1;
            }
            else if (candidate < 0)
            {
                left += 1;
            }
            else
            {
                vector<int> answer;
                answer.push_back(first);
                answer.push_back(nums[left]);
                answer.push_back(nums[right]);
                res.push_back(answer);
                
                while(left < right && nums[left + 1] == nums[left]){
                    left += 1;
                }
                
                
                while (left < right && nums[right - 1] == nums[right]) {
                    right -= 1;
                }
                
                left += 1;
                right -= 1;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
        {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (i > 0 and nums[i] == nums[i - 1])
            {
                continue;
            }
            
            twoSum(nums, i, nums[i], res);
        }
        
        return res;
    }
};
