//  Tag: Array, Dynamic Programming, Queue, Sliding Window, Prefix Sum, Monotonic Queue
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.
//  Return the total number of ways to partition nums under this condition.
//  Since the answer may be too large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: nums = [9,4,1,3,7], k = 4
//  Output: 6
//  Explanation:
//  There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:
//  
//  [[9], [4], [1], [3], [7]]
//  [[9], [4], [1], [3, 7]]
//  [[9], [4], [1, 3], [7]]
//  [[9], [4, 1], [3], [7]]
//  [[9], [4, 1], [3, 7]]
//  [[9], [4, 1, 3], [7]]
//  
//  
//  Example 2:
//  
//  Input: nums = [3,3,4], k = 0
//  Output: 2
//  Explanation:
//  There are 2 valid partitions that satisfy the given conditions:
//  
//  [[3], [3], [4]]
//  [[3, 3], [4]]
//  
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 5 * 104
//  1 <= nums[i] <= 109
//  0 <= k <= 109
//  
//  

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int mod = 1e9 + 7; 
        int prefix = 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        deque<int> minq, maxq;
        for (int i = 0, j = 0; j < n; ++j) {
            while (!maxq.empty() && nums[j] > nums[maxq.back()])
                maxq.pop_back();
            maxq.push_back(j);
            while (!minq.empty() && nums[j] < nums[minq.back()])
                minq.pop_back();
            minq.push_back(j);

            while (nums[maxq.front()] - nums[minq.front()] > k) {
                prefix = (prefix - dp[i++] + mod) % mod;
                if (minq.front() < i)
                    minq.pop_front();
                if (maxq.front() < i)
                    maxq.pop_front();
            }

            dp[j + 1] = prefix;
            prefix = (prefix + dp[j + 1]) % mod;
        }
        return dp[n];
    }
};