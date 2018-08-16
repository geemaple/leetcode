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

// two-pointers
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int left = 0;
        int right = 0;
        vector<int> ans;

        while (left < nums1.size() && right < nums2.size())
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
                ans.push_back(nums1[left]);

                while(left + 1 < nums1.size() && nums1[left + 1] == nums1[left])
                {
                    left++;
                }

                while(right + 1 < nums2.size() && nums2[right + 1] == nums2[right])
                {
                    right++;
                }

                left++;
                right++;
            }
        }

        return ans;
    }
};

