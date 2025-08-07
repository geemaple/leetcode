//  Tag: Array, Binary Search, Segment Tree, Ordered Set
//  Time: O(NLogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: TODO

//  You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
//  From left to right, place the fruits according to these rules:
//  
//  Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
//  Each basket can hold only one type of fruit.
//  If a fruit type cannot be placed in any basket, it remains unplaced.
//  
//  Return the number of fruit types that remain unplaced after all possible allocations are made.
//   
//  Example 1:
//  
//  Input: fruits = [4,2,5], baskets = [3,5,4]
//  Output: 1
//  Explanation:
//  
//  fruits[0] = 4 is placed in baskets[1] = 5.
//  fruits[1] = 2 is placed in baskets[0] = 3.
//  fruits[2] = 5 cannot be placed in baskets[2] = 4.
//  
//  Since one fruit type remains unplaced, we return 1.
//  
//  Example 2:
//  
//  Input: fruits = [3,6,1], baskets = [6,4,7]
//  Output: 0
//  Explanation:
//  
//  fruits[0] = 3 is placed in baskets[0] = 6.
//  fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
//  fruits[2] = 1 is placed in baskets[1] = 4.
//  
//  Since all fruits are successfully placed, we return 0.
//  
//   
//  Constraints:
//  
//  n == fruits.length == baskets.length
//  1 <= n <= 105
//  1 <= fruits[i], baskets[i] <= 109
//  
//  

class SegmentTree {
public:
    vector<int> seg;
    SegmentTree(vector<int> &baskets) {
        int n = baskets.size();
        int size = 4 * n;
        seg.resize(size);
        build(baskets, 1, 0, n - 1);
    }

    void update(int i) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    void build(vector<int> &baskets, int i, int l, int r) {
        if (l == r) {
            seg[i] = baskets[l];
            return;
        }

        int m = (l + r) / 2;
        build(baskets, 2 * i, l, m);
        build(baskets, 2 * i + 1, m + 1, r);
        update(i);
    }

    int query_and_update(int i, int l, int r, int val) {
        if (seg[i] < val) {
            return -1;
        }

        if (l == r) {
            seg[i] = -1; 
            return l;
        }

        int m = (l + r) / 2;
        int t = query_and_update(2 * i, l, m, val);
        if (t == -1) {
            t = query_and_update(2 * i + 1, m + 1, r, val);
        }
        update(i);
        return t;
    }

};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree tree = SegmentTree(baskets);
        int res = 0;
        for (auto &x: fruits) {
            if (tree.query_and_update(1, 0, n - 1, x) == -1) {
                res += 1;
            }
        }
        return res;
    }
};