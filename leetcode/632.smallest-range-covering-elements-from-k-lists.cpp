//  Tag: Array, Hash Table, Greedy, Sliding Window, Sorting, Heap (Priority Queue)
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
//  We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
//   
//  Example 1:
//  
//  Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
//  Output: [20,24]
//  Explanation: 
//  List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
//  List 2: [0, 9, 12, 20], 20 is in range [20,24].
//  List 3: [5, 18, 22, 30], 22 is in range [20,24].
//  
//  Example 2:
//  
//  Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
//  Output: [1,1]
//  
//   
//  Constraints:
//  
//  nums.length == k
//  1 <= k <= 3500
//  1 <= nums[i].length <= 50
//  -105 <= nums[i][j] <= 105
//  nums[i] is sorted in non-decreasing order.
//  
//  

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        int big = INT_MIN;
        for (int i = 0; i < n; i++) {
            heap.emplace(nums[i][0], 0, i);
            big = max(big, nums[i][0]);
        } 

        vector<int> res;
        while (heap.size() == n) {
            auto [small, index, arr_index] = heap.top();
            heap.pop();

            if (res.empty() || res[1] - res[0] > big - small) {
                res = {small, big};
            }

            int next_index = index + 1;
            if (next_index < nums[arr_index].size()) {
                big = max(big, nums[arr_index][next_index]);
                heap.emplace(nums[arr_index][next_index], next_index, arr_index);
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<pair<int, int>> merge;
        for (int i = 0; i < n; i++) {
            for (int x: nums[i]) {
                merge.emplace_back(x, i);
            }
        }

        sort(merge.begin(), merge.end());
        int j = 0;
        vector<int> res;
        unordered_map<int, int> count;
        int group = 0;

        for (int i = 0; i < merge.size(); i++) {
            auto [num, arr_index] = merge[i];
            count[arr_index] += 1;
            if (count[arr_index] == 1) {
                group += 1;
            }

            while (group == n) {
                if (res.empty() || res[1] - res[0] > merge[i].first - merge[j].first) {
                    res = {merge[j].first, merge[i].first};
                }
                int arr_index = merge[j].second;
                count[arr_index] -= 1;
                if (count[arr_index] == 0) {
                    group -= 1;
                }
                j += 1;
            }
        }

        return res;
    }
};