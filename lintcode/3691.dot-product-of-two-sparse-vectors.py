#  Tag: Hash Table
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-1570
#  Note: -

#  Given two sparse vectors, compute the product of their quantities (dot product).
#  
#  Implements class `SparseVector`:
#  - `SparseVector(nums)` initializes the object with the vector `nums`
#  - `dotProduct(vec)` computes the product of this vector and the `vec` vector
#  
#  **Sparse vectors** are vectors that have a majority of components **0** and are stored **efficiently** by designing the `SparseVector` class.
#  
#  The formula for the product of quantities is as follows:
#  $a \cdot b = \sum_{i = 0}^na_ib_i = a_1b_1 + a_2b_2 + ...
#  \ +a_nb_n $
#  
#  Example 1:
#  ```
#  Input:
#  nums1 = [0,0,1,2,0,3]
#  nums2 = [4,0,1,0,0,3]
#  Output:
#  10
#  Explanation:
#  v1 = SparseVector(nums1), v2 = SparseVector(nums2)
#  v1.dotProduct(v2) = 0*4 + 0*0 + 1*1 + 2*0 + 0*0 + 3*3 = 10
#  ```
#  
#  Example 2:
#  ```
#  Input:
#  nums1 = [1,0,0,0]
#  nums2 = [0,0,2,0]
#  Output:
#  0
#  Explanation:
#  v1 = SparseVector(nums1), v2 = SparseVector(nums2)
#  v1.dotProduct(v2) = 1*0 + 0*0 + 0*2 + 0*0 = 0
#  ```
#  
#  $1 \leq nums.length \leq 10^5$
#  $nums1.length == nums2.length$
#  $0 \leq nums1[i], nums2[i] \leq 1000$

from typing import (
    List,
)

class SparseVector:
    # Your SparseVector object will be instantiated and called as such:
    # v1 = SparseVector(nums1)
    # v2 = SparseVector(nums2)
    # ans = v1.dot_product(v2)
    def __init__(self, nums: List[int]):
        # do intialization here
        self.vec = []
        for i in range(len(nums)):
            if nums[i] != 0:
                self.vec.append([i, nums[i]])

    # Return the dotProduct of two sparse vectors
    def dot_product(self, vec: "SparseVector") -> int:
        # write your code here
        a = self.vec
        b = vec.vec
        res = 0
        i = 0
        j = 0
        while i < len(a) and j < len(b):
            if a[i][0] == b[j][0]:
                res += a[i][1] * b[j][1]
                i += 1
                j += 1
            elif a[i][0] < b[j][0]:
                i += 1
            else:
                j += 1
        return res