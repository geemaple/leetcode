//  Tag: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
//  Time: O(N), O(C*logK)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
//   
//  Example 1:
//  Input: nums = [1,1,1,2,2,3], k = 2
//  Output: [1,2]
//  Example 2:
//  Input: nums = [1], k = 1
//  Output: [1]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  -104 <= nums[i] <= 104
//  k is in the range [1, the number of unique elements in the array].
//  It is guaranteed that the answer is unique.
//  
//   
//  Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
//  

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        
        for(auto num: nums){
            map[num] += 1;
        }
        
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        
        for (auto it = map.begin(); it != map.end(); ++it){
            pq.push(make_pair(it->second, it->first));

            if (pq.size() > map.size() - k){
                res.push_back(pq.top().second);
                pq.pop();
            }
            
        }
        
        return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int max_count = 0;
        for (int n : nums) {
            map[n] += 1;
            if (map[n] > max_count) {
                max_count = map[n];
            }
        }

        vector<vector<int>> buckets(max_count + 1);
        for (auto it = map.begin(); it != map.end(); ++it) {
            buckets[it->second].push_back(it->first);

        }

        vector<int> res;
        for (int i = max_count; i > 0 && res.size() < k; i--) {
            for (int n : buckets[i]) {
                if (res.size() < k) {
                    res.push_back(n);
                }
            }
        }

        return res;
    }
};