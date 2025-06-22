#  Tag: Two Pointers, Array
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-1868
#  Note: -

#  **Run-length encoding** is a compression algorithm that allows an array of integer types `nums` containing many segments of **continuously repeating** numbers to be represented as a two-dimensional array `encoded`.
#  `encoded[i] = [val, freq]` represents the $i^{th}$ consecutively repeated segment of `nums` where the number `val` is repeated `freq` times.
#  
#  - For example, `nums = [1, 1, 1, 2, 2, 2, 2]` corresponds to `encoded = [[1, 3], [2, 4]]`, which means three `1` and four `2`, respectively
#  
#  The product of two trip-encoded arrays `encoded1` and `encoded2` is computed by the following steps:
#  1.
#  decompress `encoded1` and `encoded2` into complete arrays `nums1` and `nums2`, where `nums1` and `nums2` are the same length
#  2.
#  multiply the elements of both arrays with the same index subscripts to get a result array `res`, i.e.
#  `res[i] = nums1[i] * nums2[i]`
#  3.
#  compress `res` **into a stroke-encoded array and return**
#  
#  Returns the product of `encoded1` and `encoded2`, the returned trip-encoded array needs to be **compressed to a minimum length.**
#  
#  Example 1:
#  ```
#  Input:
#  encoded1 = [[1, 3], [2, 4]]
#  encoded2 = [[8, 3], [4, 4]]
#  Output:
#  [[8, 7]]
#  Explanation:
#  encoded1 unpacks as [1,1,1,2,2,2,2]
#  encoded2 unpacks as [8,8,8,4,4,4,4]
#  The product results in [8,8,8,8,8,8,8,8,8], compressed as [[8, 7]]
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  encoded1 = [[1, 3], [2, 2], [3, 1]]
#  encoded2 = [[2, 3], [3, 3]]
#  Output:
#  [[2, 3], [6, 2], [9, 1]]
#  ```
#  
#  $1 \leq encoded1.length,\  encoded2.length \leq 10^5$
#  $encoded1[i].length == 2$
#  $encoded2[j].length == 2$
#  $encoded1[i] = [val_i, \ freq_i], \ 1\leq val_i, \ freq_i \leq 10^4$
#  $encoded2[j] = [val_j, \ freq_j], \ 1\leq val_j, \ freq_j \leq 10^4$

from typing import (
    List,
)

class Solution:
    """
    @param encoded1: A run-length encoding array
    @param encoded2: A run-length encoding array
    @return: Product of two run-length encoded arrays
    """
    def find_run_length_array(self, encoded1: List[List[int]], encoded2: List[List[int]]) -> List[List[int]]:
        # write your code here
        n = len(encoded1)
        m = len(encoded2)

        res = []
        i = 0
        j = 0
        x = 0
        y = 0
        while i < n and j < m:
            tmp = encoded1[i][0] * encoded2[j][0]
            if len(res) == 0 or res[-1][0] != tmp:
                res.append([tmp, 1])
            else:
                res[-1][1] += 1

            if x + 1 < encoded1[i][1]:
                x += 1
            else:
                i += 1
                x = 0

            if y + 1 < encoded2[j][1]:
                y += 1
            else:
                j += 1
                y = 0

        return res