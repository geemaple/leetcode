//  Tag: Dynamic Programming/DP, Coordinate DP, Two Pointers
//  Time: O(N)
//  Space: O(1)
//  Ref: Leetcode-487
//  Note: -

//  Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.
//  
//  ```
//  Example 1:
//  	Input:  nums = [1,0,1,1,0]
//  	Output:  4
//  	
//  	Explanation:
//  	Flip the first zero will get the the maximum number of consecutive 1s.
//  	After flipping, the maximum number of consecutive 1s is 4.
//  
//  Example 2:
//  	Input: nums = [1,0,1,0,1]
//  	Output:  3
//  	
//  	Explanation:
//  	Flip each zero will get the the maximum number of consecutive 1s.
//  	After flipping, the maximum number of consecutive 1s is 3.
//  	
//  ```
//  
//  1. The input array will only contain `0` and `1`.
//  2. The length of input array is a positive integer and will not exceed `10,000`.

class Solution {
public:
    /**
     * @param nums: a list of integer
     * @return: return a integer, denote  the maximum number of consecutive 1s
     */
    int findMaxConsecutiveOnes(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        int res = 0;
        int i = 0;
        int zero = 0;
        for (int j = 0; j < n; j++) {
            zero += nums[j] == 0;
            while (zero > 1) {
                zero -= nums[i] == 0;
                i += 1;
            }

            res = max(res, j - i + 1);
        }

        return res;
    }
};