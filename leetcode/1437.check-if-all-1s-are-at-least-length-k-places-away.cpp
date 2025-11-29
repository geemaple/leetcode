//  Tag: Array
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
//   
//  Example 1:
//  
//  
//  Input: nums = [1,0,0,0,1,0,0,1], k = 2
//  Output: true
//  Explanation: Each of the 1s are at least 2 places away from each other.
//  
//  Example 2:
//  
//  
//  Input: nums = [1,0,0,1,0,1], k = 2
//  Output: false
//  Explanation: The second 1 and third 1 are only one apart from each other.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  0 <= k <= nums.length
//  nums[i] is 0 or 1
//  
//  

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i = -1;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 1) {
                if (i != -1 && j - i - 1 < k) {
                    return false;
                }
                i = j;
            }
        }
        return true;
    }
};