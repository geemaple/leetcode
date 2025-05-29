//  Tag: Array, Two Pointers, Binary Search, Bit Manipulation, Index Sort
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
//  There is only one repeated number in nums, return this repeated number.
//  You must solve the problem without modifying the array nums and uses only constant extra space.
//   
//  Example 1:
//  
//  Input: nums = [1,3,4,2,2]
//  Output: 2
//  
//  Example 2:
//  
//  Input: nums = [3,1,3,4,2]
//  Output: 3
//  
//  Example 3:
//  
//  Input: nums = [3,3,3,3,3]
//  Output: 3
//   
//  Constraints:
//  
//  1 <= n <= 105
//  nums.length == n + 1
//  1 <= nums[i] <= n
//  All the integers in nums appear only once except for precisely one integer which appears two or more times.
//  
//   
//  Follow up:
//  
//  How can we prove that at least one duplicate number must exist in nums?
//  Can you solve the problem in linear runtime complexity?
//  
//  

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto x: nums) {
            x = abs(x);
            if (nums[x - 1] > 0) {
                nums[x - 1] = - nums[x - 1];
            } else {
                return x;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        } while (slow != fast);

        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right =nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count_less_equal(nums, mid) <= mid) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    int count_less_equal(vector<int>& nums, int target) {
        int count = 0;
        for (auto x: nums) {
            if (x <= target) {
                count += 1;
            }
        }
        return count;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int i = 1;
        while (i < nums.size()) {
            int j = nums[i];
            if (j > 0 && j < nums.size() && nums[i] != nums[j]) {
                swap(nums[i], nums[j]);
            } else {
                i += 1;
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != i) {
                return nums[i];
            }
        }

        return -1;
    }
};