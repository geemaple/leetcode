//  Tag: Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array nums, you can perform the following operation any number of times:
//  
//  Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
//  Replace the pair with their sum.
//  
//  Return the minimum number of operations needed to make the array non-decreasing.
//  An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
//   
//  Example 1:
//  
//  Input: nums = [5,2,3,1]
//  Output: 2
//  Explanation:
//  
//  The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
//  The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
//  
//  The array nums became non-decreasing in two operations.
//  
//  Example 2:
//  
//  Input: nums = [1,2,2]
//  Output: 0
//  Explanation:
//  The array nums is already sorted.
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  
//  

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        vector<long long> vals(nums.begin(), nums.end());
        vector<int> pre(n), after(n), merged(n, false);
        for (int i = 0; i < n; ++i) {
            pre[i] = i - 1;
            after[i] = i + 1;
        }
        after[n - 1] = -1;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > heap;

        int bad = 0;
        for (int i = 1; i < n; ++i) {
            if (vals[i - 1] > vals[i]) bad++;
            heap.emplace(vals[i - 1] + vals[i], i);
        }

        int res = 0;
        while (bad > 0) {
            auto [pair_sum, r] = heap.top();
            heap.pop();

            int l = pre[r];
            if (l == -1 || merged[l] || merged[r] || 1LL * vals[l] + vals[r] != pair_sum) { 
                continue;
            }
            
            after[l] = after[r];
            if (after[r] != -1) {
                pre[after[r]] = l;
            }

            if (vals[l] > vals[r]) bad--;

            int ll = pre[l];
            if (ll != -1) {
                bad += (vals[ll] > pair_sum) - (vals[ll] > vals[l]);
                heap.emplace(vals[ll] + pair_sum, l);
            }

            int rr = after[r];
            if (rr != -1) {
                bad += (pair_sum > vals[rr]) - (vals[r] > vals[rr]);
                heap.emplace(pair_sum + vals[rr], rr);
            }

            vals[l] = pair_sum;
            merged[r] = true;
            res++;
        }

        return res;
    }
};