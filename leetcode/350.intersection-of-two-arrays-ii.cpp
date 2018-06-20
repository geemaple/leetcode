class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> res;
        
        for (auto num: nums1){
            map[num] += 1;
        }
        
        for (auto num: nums2){
            if (map[num] > 0){
                map[num] -= 1;
                res.push_back(num);
            }
        }
        
        return res;
    }
};