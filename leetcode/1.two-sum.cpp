class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i){
            int num = target - nums[i];
            if (map.find(num) != map.end()){
                res = {map[num], i};
                return res;
            }

            map.insert(make_pair(nums[i], i));
        }

        return res;
    }
};
