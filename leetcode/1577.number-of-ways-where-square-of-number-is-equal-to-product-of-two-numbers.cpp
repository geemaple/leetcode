//  Tag: Array, Hash Table, Math, Two Pointers
//  Time: O(NM)
//  Space: O(N + M)
//  Ref: -
//  Note: -

//  Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
//  
//  Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
//  Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
//  
//   
//  Example 1:
//  
//  Input: nums1 = [7,4], nums2 = [5,2,8,9]
//  Output: 1
//  Explanation: Type 1: (1, 1, 2), nums1[1]2 = nums2[1] * nums2[2]. (42 = 2 * 8). 
//  
//  Example 2:
//  
//  Input: nums1 = [1,1], nums2 = [1,1,1]
//  Output: 9
//  Explanation: All Triplets are valid, because 12 = 1 * 1.
//  Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]2 = nums2[j] * nums2[k].
//  Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]2 = nums1[j] * nums1[k].
//  
//  Example 3:
//  
//  Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
//  Output: 2
//  Explanation: There are 2 valid triplets.
//  Type 1: (3,0,2).  nums1[3]2 = nums2[0] * nums2[2].
//  Type 2: (3,0,1).  nums2[3]2 = nums1[0] * nums1[1].
//  
//   
//  Constraints:
//  
//  1 <= nums1.length, nums2.length <= 1000
//  1 <= nums1[i], nums2[i] <= 105
//  
//  

class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        unordered_map<int, int> counter1;
        unordered_map<int, int> counter2;
        for (auto &x : nums1) {
            counter1[x] += 1;
        }

        for (auto &x: nums2) {
            counter2[x] += 1;
        }

        int res = 0;
        for (auto &[x, c]: counter1) {
            res += count(nums2, counter2, 1LL * x * x) * c;
        }

        for (auto &[x, c]: counter2) {
            res += count(nums1, counter1, 1LL * x * x) * c;
        }

        return res;
    }

    int count(vector<int>& nums, unordered_map<int, int> &counter, long long target) {
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;
        while (l < r) {
            long long tmp = 1LL * nums[l] * nums[r];
            int left = counter[nums[l]];
            int right = counter[nums[r]];
            if (tmp == target) {
                if (nums[l] == nums[r]) {
                    res += left * (left - 1) / 2;
                    break;
                } else {
                    res += left * right;
                    l += left;
                    r -= right;
                }
            } else if (tmp > target) {
                r -= right;
            } else {
                l += left;
            }
        }

        return res;
    }
};