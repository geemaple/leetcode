//  Tag: Array, Two Pointers, Binary Search, Sorting
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given an array of integers nums and an integer target.
//  Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: nums = [3,5,6,7], target = 9
//  Output: 4
//  Explanation: There are 4 subsequences that satisfy the condition.
//  [3] -> Min value + max value <= target (3 + 3 <= 9)
//  [3,5] -> (3 + 5 <= 9)
//  [3,5,6] -> (3 + 6 <= 9)
//  [3,6] -> (3 + 6 <= 9)
//  
//  Example 2:
//  
//  Input: nums = [3,3,6,8], target = 10
//  Output: 6
//  Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
//  [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
//  
//  Example 3:
//  
//  Input: nums = [2,3,3,4,6,7], target = 12
//  Output: 61
//  Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
//  Number of valid subsequences (63 - 2 = 61).
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 106
//  1 <= target <= 106
//  
//  

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7;
        int l = 0;
        int r = nums.size() - 1;
        int res = 0;
        sort(nums.begin(), nums.end());
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r -= 1;
            } else {
                res = (res + pow(2, r - l, mod)) % mod;
                l += 1;
            }
        }

        return res;
    }

    int pow(int x, int power, int mod) {
        int res = 1;
        while (power) {
            if (power % 2 == 1) {
                res = (1LL * res * x) % mod;
            }
            x = (1LL * x * x) % mod;
            power /= 2;
        }
        return res;
    }
};