/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
private:
    vector<string> split(const string &target, string sep)
    {
        vector<string> results;
        int start = 0;
        int end = 0;
        while((end = target.find(sep, start)) != string::npos)
        {
            results.push_back(target.substr(start, end - start));
            start = end + sep.size();
        }
        
        if (start != target.size())
        {
            results.push_back(target.substr(start, target.size() - start));
        }
        
        return results;
    }
    
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if (root == NULL)
        {
            return "[]";
        }
        
        vector<TreeNode*> q;
        q.push_back(root);
        
        for (auto i = 0; i < q.size(); ++i)
        {
            TreeNode* node = q[i];
            if (node)
            {
                q.push_back(node->left);
                q.push_back(node->right);
            }
        }
        
        while(q.size() >0 && q[q.size() - 1] == NULL)
        {
            q.pop_back();
        }
        
        stringstream ss;
        ss << "[" << q[0]->val;
        for (auto i = 1; i < q.size(); ++i)
        {
            if (q[i])
            {
                ss << "," << q[i]->val;
            }
            else
            {
                ss << "," << "#";
            }
        }
        
        ss << "]";
        
        return ss.str();
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if (data == "[]")
        {
            return NULL;
        }
        
        vector<string> nodes = split(data.substr(1, data.size() - 2), ",");
        TreeNode* root = new TreeNode(atoi(nodes[0].c_str()));
        queue<TreeNode*> q;
        q.push(root);
        
        bool isLeft = true;
        for (auto i = 1; i < nodes.size(); ++i)
        {
            if (nodes[i] != "#")
            {
                TreeNode* child = new TreeNode(atoi(nodes[i].c_str()));
                if (isLeft)
                {
                    q.front()->left = child;
                }
                else
                {
                    q.front()->right = child;
                }
                q.push(child);
            }
            
            if (!isLeft)
            {
                q.pop();
            }
            
            isLeft = !isLeft;
        }
        
        return root;
    }
};