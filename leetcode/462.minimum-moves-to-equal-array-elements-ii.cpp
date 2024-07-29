//  Tag: Array, Math, Sorting
//  Time: O(NlogN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
//  In one move, you can increment or decrement an element of the array by 1.
//  Test cases are designed so that the answer will fit in a 32-bit integer.
//   
//  Example 1:
//  
//  Input: nums = [1,2,3]
//  Output: 2
//  Explanation:
//  Only two moves are needed (remember each move increments or decrements one element):
//  [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
//  
//  Example 2:
//  
//  Input: nums = [1,10,2,9]
//  Output: 16
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  
//  

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int median = nums[n / 2];
        int res = 0;
        for (auto x: nums) {
            res += abs(x - median);
        }
        return res;
    }
};

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int median = quick_select(nums, 0, n - 1, n / 2);
        int res = 0;
        for (auto x: nums) {
            res += abs(x - median);
        }
        return res;
    }

    int quick_select(vector<int>& nums, int left, int right, int nth) {
        int select = rand() % (right - left + 1) + left;
        int value = nums[select];
        swap(nums[left], nums[select]);
        int l = left + 1;
        int r = right;
        while (l <= r) {
            while (l <= r && nums[l] < value) {
                l++;
            }

            while (l <= r && nums[r] >= value) {
                r--;
            }

            if (l <= r) {
                swap(nums[l], nums[r]);
            }
        }

        swap(nums[left], nums[r]);
        if (r > nth) {
            return quick_select(nums, left, r - 1, nth);
        } else if (r < nth) {
            return quick_select(nums, r + 1, right, nth);
        }  else {
            return nums[r];
        }
    }
};