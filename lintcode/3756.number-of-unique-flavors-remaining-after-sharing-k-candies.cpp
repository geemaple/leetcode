//  Tag: Hash Table, Sliding Window, Two Pointers
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-2107
//  Note: -

//  Given an integer array `candies` with indices starting from **0**, where `candies[i]` represents the **flavor** of the $i^{th}$ candy.
//  
//  Now, you want to share these candies with your friend.
//  You will give away `k` **consecutive** candies and aim to keep as many unique candy flavors as possible.
//  
//  After sharing with your friend, return the **maximum number** of **unique** candy flavors that can be preserved.
//  
//  **Example 1**
//  
//  Input:
//  ```
//  candies = [1,2,2,3,4,3]
//  k = 3
//  ```
//  
//  Output:
//  ```
//  3
//  ```
//  
//  Explanation:
//  ```
//  You can share the candies [2,2,3] from the range [1,3] with your friend.
//  Afterward, you can have the remaining candies [1,4,3] for yourself.
//  There are 3 unique flavors, so the return value is 3.
//  ```
//  
//  **Example 2**
//  
//  Input:
//  ```
//  candies = [2,2,2,2,3,3]
//  k = 2
//  ```
//  
//  Output:
//  ```
//  2
//  ```
//  
//  Explanation:
//  ```
//  You can share either the candies [2,3] or the candies [2,2] from the range [3,4] with your friend.
//  Afterward, you can have the remaining candies [2,2,2,3] or [2,2,3,3] for yourself.
//  There are 2 unique flavors, so the return value is 2.
//  ```
//  
//  **Example 3**
//  
//  Input:
//  ```
//  candies = [2,4,5,7]
//  k = 0
//  ```
//  
//  Output:
//  ```
//  4
//  ```
//  
//  Explanation:
//  ```
//  You don't need to share any candies with your friend.
//  You can have all the candies [2,4,5,7] for yourself.
//  There are 4 unique flavors, so the return value is 4.
//  ```
//  
//  $1 \le candies.length \le 10^5$
//  
//  $1 \le candies[i] \le 10^5$
//  
//  $0 \le k  \le candies.length$

class Solution {
public:
    /**
     * @param candies: The flavors of your candies.
     * @param k: The number of candies you need to share.
     * @return: The maximum number of unique flavors remaining.
     */
    int maximumUniqueFlavors(vector<int> &candies, int k) {
        // --- write your code here ---
        int n = candies.size();
        unordered_map<int, int> counter;
        for (int x: candies) {
            counter[x] += 1;
        }

        int give = counter.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i >= k) {
                counter[candies[i - k]] += 1;
                if (counter[candies[i - k]] == 1) {
                    count -= 1;
                }
            }

            counter[candies[i]] -= 1;
            if (counter[candies[i]] == 0) {
                count += 1;
            }

            if (i >= k - 1) {
                give = min(give, count);
            } 
        }

        return counter.size() - give;
    }
};