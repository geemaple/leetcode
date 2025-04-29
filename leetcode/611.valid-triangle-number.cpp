//  Tag: Array, Two Pointers, Binary Search, Greedy, Sorting
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, return the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//   
//  Example 1:
//  
//  Input: nums = [2,2,3,4]
//  Output: 3
//  Explanation: Valid combinations are: 
//  2,3,4 (using the first 2)
//  2,3,4 (using the second 2)
//  2,2,3
//  
//  Example 2:
//  
//  Input: nums = [4,2,3,4]
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 1000
//  0 <= nums[i] <= 1000
//  
//  

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int k = 2; k < n; k++) {
            int l = 0;
            int r = k - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[k]) {
                    res += r - l;
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
        return res;
    }
};