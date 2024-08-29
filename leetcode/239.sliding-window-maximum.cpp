//  Tag: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
//  Time: O(N)
//  Space: O(K)
//  Ref: -
//  Note: -

//  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//  Return the max sliding window.
//   
//  Example 1:
//  
//  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//  Output: [3,3,5,5,6,7]
//  Explanation: 
//  Window position                Max
//  ---------------               -----
//  [1  3  -1] -3  5  3  6  7       3
//   1 [3  -1  -3] 5  3  6  7       3
//   1  3 [-1  -3  5] 3  6  7       5
//   1  3  -1 [-3  5  3] 6  7       5
//   1  3  -1  -3 [5  3  6] 7       6
//   1  3  -1  -3  5 [3  6  7]      7
//  
//  Example 2:
//  
//  Input: nums = [1], k = 1
//  Output: [1]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  -104 <= nums[i] <= 104
//  1 <= k <= nums.length
//  
//  

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!q.empty() && i - q.front() == k) {
                q.pop_front();
            }

            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }

            q.push_back(i);
            if (i + 1 >= k) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            while (!q.empty() && i - q.top().second >= k) {
                q.pop();
            }

            q.push({nums[i], i});
            if (i + 1 >= k) {
                res.push_back(q.top().first);
            }
        }

        return res;
    }   
};