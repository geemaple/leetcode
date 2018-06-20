class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for (auto i = 0; i < nums.size(); ++i){
            
            if (map.count(nums[i]) > 0){
                if (abs(map[nums[i]] - i) <= k){
                    return true;
                }
            }
            
            map[nums[i]] = i;
        }
        
        return false;
    }
};