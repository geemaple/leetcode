//  Tag: Array, Hash Table, Sliding Window, Heap (Priority Queue)
//  Time: O(NlogK)
//  Space: O(K)
//  Ref: -
//  Note: -

//  The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
//  
//  For examples, if arr = [2,3,4], the median is 3.
//  For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
//  
//  You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//  Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
//   
//  Example 1:
//  
//  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
//  Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
//  Explanation: 
//  Window position                Median
//  ---------------                -----
//  [1  3  -1] -3  5  3  6  7        1
//   1 [3  -1  -3] 5  3  6  7       -1
//   1  3 [-1  -3  5] 3  6  7       -1
//   1  3  -1 [-3  5  3] 6  7        3
//   1  3  -1  -3 [5  3  6] 7        5
//   1  3  -1  -3  5 [3  6  7]       6
//  
//  Example 2:
//  
//  Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
//  Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
//  
//   
//  Constraints:
//  
//  1 <= k <= nums.length <= 105
//  -231 <= nums[i] <= 231 - 1
//  
//  

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int, greater<int>> max_set;
        multiset<int, less<int>> min_set;
        vector<double> res;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                if (max_set.count(nums[i - k]) > 0) {
                    max_set.erase(max_set.find(nums[i - k]));
                } else {
                    min_set.erase(min_set.find(nums[i - k]));
                }
            }

            max_set.insert(nums[i]);
            min_set.insert(*max_set.begin());
            max_set.erase(max_set.begin());
            if (max_set.size() < min_set.size()) {
                max_set.insert(*min_set.begin());
                min_set.erase(min_set.begin());
            }

            if (i >= k - 1) {
                if (k & 1) {
                    res.push_back((double)*max_set.begin());
                } else {
                    res.push_back(((double)*max_set.begin() + (double)*min_set.begin()) / 2.0);
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> medians;
        for (int i=k; ; i++) {
            // Push the current median.
            medians.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);

            // If all done, return.
            if (i == nums.size())
                return medians;
                
            // Insert nums[i].
            window.insert(nums[i]);
            if (nums[i] < *mid)
                mid--;

            // Erase nums[i-k].
            if (nums[i-k] <= *mid)
                mid++;
            window.erase(window.lower_bound(nums[i-k]));
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       function<bool(const pair<int, int>&, const pair<int, int>&)>>
            max_heap([](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first || (a.first == b.first && a.second > b.second);
            });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        
        for (int i = 0; i < k; i++) {
            max_heap.emplace(nums[i], i);
        }

        for (int i = 0; i < k / 2; i++) {
            auto [number, index] = max_heap.top();
            max_heap.pop();
            min_heap.emplace(number, index);
        }
        vector<double> res;
        double val = (k % 2 == 1) ? (double)max_heap.top().first : ((double)max_heap.top().first + (double)min_heap.top().first) / 2.0;
        res.push_back(val);

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] <= max_heap.top().first) {
                max_heap.emplace(nums[i], i);
                if (nums[i - k] >= max_heap.top().first) {
                    auto [number, index] = max_heap.top();
                    max_heap.pop();
                    min_heap.emplace(number, index);
                }
            } else {
                min_heap.emplace(nums[i], i);
                if (nums[i - k] <= max_heap.top().first) {
                    auto [number, index] = min_heap.top();
                    min_heap.pop();
                    max_heap.emplace(number, index);
                }
            }

            while (!max_heap.empty() && max_heap.top().second <= i - k) {
                max_heap.pop();
            }

            while (!min_heap.empty() && min_heap.top().second <= i - k) {
                min_heap.pop();
            }

            double val = (k % 2 == 1) ? (double)max_heap.top().first : ((double)max_heap.top().first + (double)min_heap.top().first) / 2.0;
            res.push_back(val);
        }

        return res;
    }
};