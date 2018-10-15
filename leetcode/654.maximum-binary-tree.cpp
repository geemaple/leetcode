/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return NULL;
        }
        
        nums.push_back(INT_MAX);
        
        int m = nums.size();
        vector<TreeNode *> table;
        
        for (auto i = 0; i < m; ++i)
        {
            TreeNode *node = new TreeNode(nums[i]);
            table.push_back(node);
        }
        
        stack<int> st;
        for (auto i = 0; i < m; ++i)
        {
            while(!st.empty() && nums[st.top()] <= nums[i])
            {
                int index = st.top();
                st.pop();
                
                int left = st.empty() ? INT_MAX: nums[st.top()];
                
                if (left < nums[i])
                {
                    table[st.top()]->right = table[index];
                }
                else
                {
                    table[i]->left = table[index];
                }
            }
            
            st.push(i);
        }
        
        return table[m - 1]->left;
    }
};