//  Tag: Array, Hash Table, Math, Counting
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/TT0RLW7eljE

//  You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
//  Return the total number of bad pairs in nums.
//   
//  Example 1:
//  
//  Input: nums = [4,1,3,3]
//  Output: 5
//  Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
//  The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
//  The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
//  The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
//  The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
//  There are a total of 5 bad pairs, so we return 5.
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,4,5]
//  Output: 0
//  Explanation: There are no bad pairs.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 109
//  
//  


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int pre = counter[nums[i] - i];
            res += i - pre;
            counter[nums[i] - i] += 1;
        }
        return res;
    }
};

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        long long bad = 0;
        for (int i = 0; i < n; i++) {
            int pre = counter[nums[i] - i];
            bad += pre;
            counter[nums[i] - i] += 1;
        }
        return 1L * n * (n - 1) / 2 - bad;
    }
};