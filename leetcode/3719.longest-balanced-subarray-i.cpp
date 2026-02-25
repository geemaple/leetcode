//  Tag: Array, Hash Table, Divide and Conquer, Segment Tree, Prefix Sum
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an integer array nums.
//  A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
//  Return the length of the longest balanced subarray.
//   
//  Example 1:
//  
//  Input: nums = [2,5,4,3]
//  Output: 4
//  Explanation:
//  
//  The longest balanced subarray is [2, 5, 4, 3].
//  It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
//  
//  
//  Example 2:
//  
//  Input: nums = [3,2,2,5,4]
//  Output: 5
//  Explanation:
//  
//  The longest balanced subarray is [3, 2, 2, 5, 4].
//  It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
//  
//  
//  Example 3:
//  
//  Input: nums = [1,2,3,2]
//  Output: 3
//  Explanation:
//  
//  The longest balanced subarray is [2, 3, 2].
//  It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
//  
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 1500
//  1 <= nums[i] <= 105
//  
//  

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (i > n - res) break;

            int count[2] = {0, 0};

            for (int j = i; j < n; ++j) {
                int x = nums[j];
                if (seen.find(x) == seen.end()) {
                    count[x & 1]++;
                    seen.insert(x);
                }

                if (count[0] == count[1]) {
                    res = max(res, j - i + 1);
                }
            }

            seen.clear();
        }

        return res; 
    }
};