//  Tag: Array, Binary Search, Divide and Conquer, Binary Indexed Tree, Segment Tree, Merge Sort, Ordered Set
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/xWhiSWNeLtk

//  You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].
//  A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.
//  Return the total number of good triplets.
//   
//  Example 1:
//  
//  Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
//  Output: 1
//  Explanation: 
//  There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
//  Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
//  
//  Example 2:
//  
//  Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
//  Output: 4
//  Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
//  
//   
//  Constraints:
//  
//  n == nums1.length == nums2.length
//  3 <= n <= 105
//  0 <= nums1[i], nums2[i] <= n - 1
//  nums1 and nums2 are permutations of [0, 1, ..., n - 1].
//  
//  

class BitTree {
public:
    int n;
    vector<int> arr;
    BitTree(int size) {
        n = size;
        arr.resize(size + 1);
    }

    void update(int i, int delta) {
        i = i + 1;
        while (i <= n) {
            arr[i] += delta;
            i += i & -i;
        }
    }
    
    int query(int i) {
        int res = 0;
        i = i + 1;
        while (i > 0) {
            res += arr[i];
            i -= i & -i;
        }
        return res;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> indexes(n, 0);
        for (int i = 0; i < n; i++) {
            indexes[nums2[i]] = i;
        }

        BitTree bit(n);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            int mid = indexes[nums1[i]];
            int small = bit.query(mid);
            int big = n - 1 - mid - (i - small);
            res += 1LL * big * small;
            bit.update(mid, 1);
        }
        return res;
    }
};