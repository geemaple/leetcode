//  Tag: Array, Queue, Sliding Window, Heap (Priority Queue), Ordered Set, Monotonic Queue
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
//  
//  Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
//  
//  Return the total number of continuous subarrays.
//  A subarray is a contiguous non-empty sequence of elements within an array.
//   
//  Example 1:
//  
//  Input: nums = [5,4,2,4]
//  Output: 8
//  Explanation: 
//  Continuous subarray of size 1: [5], [4], [2], [4].
//  Continuous subarray of size 2: [5,4], [4,2], [2,4].
//  Continuous subarray of size 3: [4,2,4].
//  There are no subarrys of size 4.
//  Total continuous subarrays = 4 + 3 + 1 = 8.
//  It can be shown that there are no more continuous subarrays.
//  
//   
//  Example 2:
//  
//  Input: nums = [1,2,3]
//  Output: 6
//  Explanation: 
//  Continuous subarray of size 1: [1], [2], [3].
//  Continuous subarray of size 2: [1,2], [2,3].
//  Continuous subarray of size 3: [1,2,3].
//  Total continuous subarrays = 3 + 2 + 1 = 6.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 109
//  
//  

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long res = 0;
        deque<int> minq, maxq;
        for (int j = 0; j < n; j++) {
            while (!maxq.empty() && nums[j] > nums[maxq.back()]) {
                maxq.pop_back();
            }
            maxq.push_back(j);

            while (!minq.empty() && nums[j] < nums[minq.back()]) {
                minq.pop_back();
            }
            minq.push_back(j);

            while (nums[maxq.front()] - nums[minq.front()] > 2) {
                if (i == maxq.front()) {
                    maxq.pop_front();
                }

                if (i == minq.front()) {
                    minq.pop_front();
                }
                i += 1;
            }
            res += j - i + 1;
        }
        return res;
    }
};

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long res = 0;
        multiset<int> win;
        for (int j = 0; j < n; j++) {
            win.insert(nums[j]);
            while (*win.rbegin() - *win.begin() > 2) {
                win.erase(win.find(nums[i]));
                i += 1;
            }
            res += j - i + 1;
        }
        return res;
    }
};