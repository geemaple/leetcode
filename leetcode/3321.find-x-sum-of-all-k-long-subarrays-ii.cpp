//  Tag: Array, Hash Table, Sliding Window, Heap (Priority Queue)
//  Time: O(NLogK)
//  Space: O(K)
//  Ref: -
//  Note: -

//  You are given an array nums of n integers and two integers k and x.
//  The x-sum of an array is calculated by the following procedure:
//  
//  Count the occurrences of all elements in the array.
//  Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
//  Calculate the sum of the resulting array.
//  
//  Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
//  Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
//   
//  Example 1:
//  
//  Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
//  Output: [6,10,12]
//  Explanation:
//  
//  For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
//  For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
//  For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
//  
//  
//  Example 2:
//  
//  Input: nums = [3,8,7,8,7,5], k = 2, x = 2
//  Output: [11,15,15,15,12]
//  Explanation:
//  Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
//  
//   
//  Constraints:
//  
//  nums.length == n
//  1 <= n <= 105
//  1 <= nums[i] <= 109
//  1 <= x <= k <= nums.length
//  
//  

class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> counter;
        set<pair<long long, int>> top;
        set<pair<long long, int>> bottom;
        vector<long long> res;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long count = counter[nums[i]];
            pair<long long, int> p = {count, nums[i]};
            auto it = bottom.find(p);
            if (it != bottom.end()) {
                bottom.erase(it);
            } else {
                top.erase(p);
                ans -= count * nums[i];
            }

            counter[nums[i]] = count + 1;
            ans += (count + 1) * nums[i];
            top.insert({count + 1, nums[i]});
            if (top.size() > x) {
                auto it = top.begin();
                ans -= it->first * it->second;
                bottom.insert({it->first, it->second});
                top.erase(it);
            }

            if (i >= k - 1) {
                res.push_back(ans);

                long long count = counter[nums[i - k + 1]];
                pair<long long, int> p = {count, nums[i - k + 1]};
                auto it = bottom.find(p);
                if (it != bottom.end()) {
                    bottom.erase(it);
                } else {
                    it = top.find(p);
                    ans -= it->first * it->second;
                    top.erase(it);
                }

                if (count > 1) {
                    bottom.insert({count - 1, nums[i - k + 1]});
                }       

                if (top.size() < x && !bottom.empty()) {
                    auto it = prev(bottom.end());
                    top.insert({it->first, it->second});
                    ans += it->first * it->second;
                    bottom.erase(it);
                }

                counter[nums[i - k + 1]] -= 1;
            }

        }

        return res;
    }
};