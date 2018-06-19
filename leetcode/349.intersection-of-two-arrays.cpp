class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.empty() || nums2.empty()){
            return vector<int>();
        }

        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        for (int num: nums2){
            if (set.count(num) > 0){
                res.push_back(num);
                set.erase(num);
            }
        }
        return res;
    }
};
