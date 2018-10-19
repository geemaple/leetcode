/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    TreeNode *cur = NULL;
    stack<TreeNode *>st;
public:
    BSTIterator(TreeNode *root) {
        cur = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return cur || !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        while(cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        
        TreeNode *tmp = st.top();
        st.pop();
        cur = tmp->right;
        
        return tmp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */