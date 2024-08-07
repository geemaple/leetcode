//  Tag: Array, Design, Binary Indexed Tree, Segment Tree
//  Time: O(logN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array nums, handle multiple queries of the following types:
//  
//  Update the value of an element in nums.
//  Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
//  
//  Implement the NumArray class:
//  
//  NumArray(int[] nums) Initializes the object with the integer array nums.
//  void update(int index, int val) Updates the value of nums[index] to be val.
//  int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
//  
//   
//  Example 1:
//  
//  Input
//  ["NumArray", "sumRange", "update", "sumRange"]
//  [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
//  Output
//  [null, 9, null, 8]
//  
//  Explanation
//  NumArray numArray = new NumArray([1, 3, 5]);
//  numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
//  numArray.update(1, 2);   // nums = [1, 2, 5]
//  numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 3 * 104
//  -100 <= nums[i] <= 100
//  0 <= index < nums.length
//  -100 <= val <= 100
//  0 <= left <= right < nums.length
//  At most 3 * 104 calls will be made to update and sumRange.
//  
//  

class SegmentTreeNode {
public:
    int start, end, val;
    SegmentTreeNode *left, *right;
    ~SegmentTreeNode(){
        delete left;
        delete right;
    }
    SegmentTreeNode(int start, int end, int val)
        : start(start), end(end), val(val), left(nullptr), right(nullptr) {}
};

class SegmentTree {
public:
    SegmentTreeNode* root;
    ~SegmentTree(){
        delete root;
    }
    SegmentTree(const std::vector<int>& nums) {
        root = build(nums, 0, nums.size() - 1);
    }

    SegmentTreeNode* build(const std::vector<int>& nums, int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, nums[start]);
        }

        int mid = (start + end) / 2;
        SegmentTreeNode* node = new SegmentTreeNode(start, end, 0);
        node->left = build(nums, start, mid);
        node->right = build(nums, mid + 1, end);
        node->val = node->left->val + node->right->val;
        return node;
    }

    void update(SegmentTreeNode* node, int index, int val) {
        if (node->start == node->end) {
            node->val = val;
            return;
        }

        int mid = (node->start + node->end) / 2;
        if (index <= mid) {
            update(node->left, index, val);
        } else {
            update(node->right, index, val);
        }

        node->val = node->left->val + node->right->val;
    }

    int query(SegmentTreeNode* node, int start, int end) {
        if (start == node->start && end == node->end) {
            return node->val;
        }

        int mid = (node->start + node->end) / 2;
        if (end <= mid) {
            return query(node->left, start, end);
        } else if (start > mid) {
            return query(node->right, start, end);
        } else {
            int left_val = query(node->left, start, mid);
            int right_val = query(node->right, mid + 1, end);
            return left_val + right_val;
        }
    }

};

class NumArray {
    SegmentTree tree;
public:
    NumArray(vector<int>& nums): tree(nums) {}
    
    void update(int index, int val) {
        tree.update(tree.root, index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.query(tree.root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */