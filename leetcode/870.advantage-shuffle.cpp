//  Tag: Array, Two Pointers, Greedy, Sorting
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
//  Return any permutation of nums1 that maximizes its advantage with respect to nums2.
//   
//  Example 1:
//  Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
//  Output: [2,11,7,15]
//  Example 2:
//  Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
//  Output: [24,32,8,12]
//  
//   
//  Constraints:
//  
//  1 <= nums1.length <= 105
//  nums2.length == nums1.length
//  0 <= nums1[i], nums2[i] <= 109
//  
//  

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> nums2_index;
        for (int i = 0; i < n; i++) {
            nums2_index.push_back(make_pair(nums2[i], i));
        }
        sort(nums2_index.begin(), nums2_index.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        });

        int l = 0;
        int r = n - 1;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums1[r] > nums2_index[i].first) {
                res[nums2_index[i].second] = nums1[r];
                r--;
            } else {
                res[nums2_index[i].second] = nums1[l];
                l++;
            }   
        }

        return res;
    }
};    