// hash
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

// two-pointers
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int left = 0;
        int right = 0;

        vector<int> res;
        while(left < nums1.size() && right < nums2.size())
        {
            if (nums1[left] > nums2[right])
            {
                right++;
            }
            else if (nums1[left] < nums2[right])
            {
                left++;
            }
            else
            {
                res.push_back(nums1[left]);
                left++;
                right++;
            }
        }

        return res;
    }
};
