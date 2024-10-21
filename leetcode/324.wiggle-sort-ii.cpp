//  Tag: Array, Divide and Conquer, Greedy, Sorting, Quickselect
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
//  You may assume the input array always has a valid answer.
//   
//  Example 1:
//  
//  Input: nums = [1,5,1,1,6,4]
//  Output: [1,6,1,5,1,4]
//  Explanation: [1,4,1,5,1,6] is also accepted.
//  
//  Example 2:
//  
//  Input: nums = [1,3,2,2,3,1]
//  Output: [2,3,1,3,1,2]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 5 * 104
//  0 <= nums[i] <= 5000
//  It is guaranteed that there will be an answer for the given input nums.
//  
//   
//  Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int index = n - 1;

        for (int i = 1; i < n; i+=2) {
            nums[i] = tmp[index--];
        }

       for (int i = 0; i < n; i+=2) {
            nums[i] = tmp[index--];
        }
    }
};

// follow-up
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        auto midptr = nums.begin() + right / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int medean = *midptr;

        auto V = [&](int i) {
            return (1 + 2 * i) % (n | 1);
        };

        int i = 0;
        while (i <= right) {
            if (nums[V(i)] > medean) {
                swap(nums[V(i)], nums[V(left)]);
                i ++;
                left ++;
            } else if (nums[V(i)] < medean) {
                swap(nums[V(i)], nums[V(right)]);
                right --;
            } else {
                i ++;
            }
        }
    }
};