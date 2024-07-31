//  Tag: Array, Divide and Conquer, Quickselect, Sorting, Heap (Priority Queue)
//  Time: O(N) ～ O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: QuickSelection

//  Given an integer array nums and an integer k, return the kth largest element in the array.
//  Note that it is the kth largest element in the sorted order, not the kth distinct element.
//  Can you solve it without sorting?
//   
//  Example 1:
//  Input: nums = [3,2,1,5,6,4], k = 2
//  Output: 5
//  Example 2:
//  Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= k <= nums.length <= 105
//  -104 <= nums[i] <= 104
//  
//  

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // min_heap using pq
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end()); //max_heap using multiset
        for (int i = 0; i < k - 1; i++) {
            mset.erase(mset.begin());
        }
        return *mset.begin();
    }
};

class Solution {
private:
    int partition(vector<int>& nums, int start, int end) {
        int l = start + 1;
        int r = end;
        int pivot = nums[start];

        while (l <= r) {
            if (nums[l] > pivot && nums[r] < pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] <= pivot) {
                l++;
            }
            if (nums[r] >= pivot) {
                r--;
            }
        }
        swap(nums[start], nums[r]);
        return r;
    }

public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int start = 0;
        int end = (int)nums.size() - 1;
        k = nums.size() - k;

        while(start < end) {
            int mid = partition(nums, start, end);
            if (mid < k) {   
                start = mid + 1;
            } else if (mid > k) {
                end = mid - 1;
            } else {
                break;
            }
        }

        return nums[k];
    }
};
