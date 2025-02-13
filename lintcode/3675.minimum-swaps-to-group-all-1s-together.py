#  Tag: Sliding Window, Array
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-1151
#  Note: -

#  In this problem there is a binary array (contains only 0 and 1).
#  You can swap arbitrary elements of the array.
#  
#  Now you need to combine all 1s in the array.
#  Returns the minimum number of swaps required for a combination.
#  
#  **Example 1**
#  
#  Input：
#  
#  ```plaintext
#  [1,0,1,0,1]
#  ```
#  
#  Explanation:
#  
#  `[1,1,1,0,0]` or `[0,0,1,1,1]` only need one swap.
#  
#  Output:
#  
#  ```plaintext
#  1
#  ```
#  
#  **Example 2**
#  
#  Input:
#  
#  ```plaintext
#  [1,0,1,0,1,0,1,1,0,1]
#  ```
#  
#  Output:
#  
#  ```plaintext
#  2
#  ```
#  
#  Explanation:
#  
#  `[0,0,0,0,1,1,1,1,1,1]` requires only two swaps.
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param arr: the binary array
    @return: the minimal number of  swaps
    """
    def min_swaps(self, arr: List[int]) -> int:
        # write your code here
        n = len(arr)
        k = arr.count(1)
        ones = 0
        count = 0
        i = 0
        for j in range(n):
            if arr[j] == 1:
                count += 1
            if j - i + 1 == k:
                ones = max(ones, count)
                if arr[i] == 1:
                    count -= 1
                i += 1

        return k - ones