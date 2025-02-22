//  Tag: Same Direction Two Pointers, Greedy, Two Pointers
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-683
//  Note: -

//  There is a garden with `N` slots.
//  In each slot, there is a flower.
//  The `N` flowers will bloom one by one in `N` days.
//  In each day, there will be `exactly` one flower blooming and it will be in the status of blooming since then.
//  
//  Given an array `flowers` consists of number from `1` to `N`.
//  Each number in the array represents the place where the flower will open in that day.
//  
//  For example, `flowers[i] = x` means that the unique flower that blooms at day `i` will be at position `x`, where `i` and `x` will be in the range from `1` to `N`.
//  
//  Also given an integer `k`, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is `k` and these flowers are not blooming.
//  
//  If there are multiple answers, choose the smallest.
//  If there isn't such day, output -1.
//  
//  **Example 1:**
//  ```
//  Input：[1,2,3,4]，k=1
//  Output：-1
//  Explanation：The first two flowers to open are next to each other.
//  ```
//  **Example 2:**
//  ```
//  Input：[1,3,2]，k=1
//  Output：2
//  Explanation：In the second day, the first and the third flower have become blooming.
//  ```
//  
//  * The given array will be in the range `[1, 20000]`.

class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        // Write your code here
        int n = flowers.size();
        vector<int> bloom(n);  
        for (int i = 0; i < n; i++) {
            bloom[flowers[i] - 1] = i + 1;
        }

        int left = 0; 
        int right = left + k + 1;
        int result = INT_MAX;

        for (int i = 1; right < n; i++) {
            if (i == right) {
                result = min(result, max(bloom[left], bloom[right]));
            }

            if (bloom[i] < bloom[left] || bloom[i] < bloom[right]) {
                left = i;
                right = left + k + 1;
            }
        }

        return (result == INT_MAX) ? -1 : result;
    }
};

class Solution {
public:
    /**
     * @param flowers: the place where the flower will open in that day
     * @param k:  an integer
     * @return: in which day meet the requirements
     */
    int kEmptySlots(vector<int> &flowers, int k) {
        // Write your code here
        set<int> bloom;
        
        for (auto i = 0; i < flowers.size(); ++i) {
            auto lower = bloom.lower_bound(flowers[i]);
            if (lower != bloom.begin() && flowers[i] - *(--lower) == k + 1) {
                return i + 1;
            }
  
            auto upper = bloom.upper_bound(flowers[i]);
            if (upper != bloom.end() && *upper - flowers[i] == k + 1) {
                return i + 1;
            }
            
            bloom.insert(flowers[i]);
        }
        
        return -1;
    }
};