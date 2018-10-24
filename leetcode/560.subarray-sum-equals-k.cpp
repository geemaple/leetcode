class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix_sum = 0;
        unordered_map<int, vector<int>> map;
        map[k] = vector<int>(1, -1);
        int count = 0;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            prefix_sum += nums[i];
            if (map.count(prefix_sum) != 0)
            {
                count += map[prefix_sum].size();
            }
            map[prefix_sum + k].push_back(i);
        }
        
        return count;
    }
};