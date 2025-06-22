//  Tag: Hash Table
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-1570
//  Note: -

//  Given two sparse vectors, compute the product of their quantities (dot product).
//  
//  Implements class `SparseVector`:
//  - `SparseVector(nums)` initializes the object with the vector `nums`
//  - `dotProduct(vec)` computes the product of this vector and the `vec` vector
//  
//  **Sparse vectors** are vectors that have a majority of components **0** and are stored **efficiently** by designing the `SparseVector` class.
//  
//  The formula for the product of quantities is as follows:
//  $a \cdot b = \sum_{i = 0}^na_ib_i = a_1b_1 + a_2b_2 + ...
//  \ +a_nb_n $
//  
//  Example 1:
//  ```
//  Input:
//  nums1 = [0,0,1,2,0,3]
//  nums2 = [4,0,1,0,0,3]
//  Output:
//  10
//  Explanation:
//  v1 = SparseVector(nums1), v2 = SparseVector(nums2)
//  v1.dotProduct(v2) = 0*4 + 0*0 + 1*1 + 2*0 + 0*0 + 3*3 = 10
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  nums1 = [1,0,0,0]
//  nums2 = [0,0,2,0]
//  Output:
//  0
//  Explanation:
//  v1 = SparseVector(nums1), v2 = SparseVector(nums2)
//  v1.dotProduct(v2) = 1*0 + 0*0 + 0*2 + 0*0 = 0
//  ```
//  
//  $1 \leq nums.length \leq 10^5$
//  $nums1.length == nums2.length$
//  $0 \leq nums1[i], nums2[i] \leq 1000$

class SparseVector {
public:
    // Your SparseVector object will be instantiated and called as such:
    // SparseVector v1(nums1);
    // SparseVector v2(nums2);
    // int ans = v1.dotProduct(v2);
    vector<pair<int, int>> v;
    SparseVector(vector<int>& nums) {
        // do intialization here
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                v.emplace_back(i, nums[i]);
            }
        }

    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        // write your code here
        vector<pair<int, int>> &a = v;
        vector<pair<int, int>> &b = vec.v;
        int i = 0;
        int j = 0;
        int res = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i].first == b[j].first) {
                res += a[i].second * b[j].second;
                i += 1;
                j += 1;
            } else if (a[i].first < b[j].first) {
                i += 1;
            } else {
                j += 1;
            }
        }

        return res;
    }
};