class Solution {
private:
    int twoSum(vector<int>& nums, int start, int target, int result){
        
        int left = start + 1;
        int right = nums.size() - 1;
        
        while(left < right){
            int candidate = nums[start] + nums[left] + nums[right];
            if (abs(candidate - target) < abs(result - target))
            {
                result = candidate;
            }
            
            if (candidate > target)
            {
                right -= 1;
            }
            else if(candidate < target)
            {
                left += 1;
            }
            else
            {
                break;
            }
        }
        
        return result;
    }
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int result = nums[0] + nums[1] + nums[3];
        sort(nums.begin(), nums.end());
    
        for (auto i = 0; i < nums.size(); ++i)
        {
            result = twoSum(nums, i, target, result);
        }
        
        return result;
    }
};
