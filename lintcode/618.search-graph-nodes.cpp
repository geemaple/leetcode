/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
                                        
        
        if (node == NULL || graph.size() == 0 || values.size() == 0)
        {
            return NULL;
        }
                                        
        // write your code here
        unordered_set<UndirectedGraphNode *> visited;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        visited.insert(node);
        
        while (!q.empty())
        {
            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                UndirectedGraphNode *tmp = q.front();
                q.pop();
                
                if (values[tmp] == target)
                {
                    return tmp;
                }
                
                for (auto neightbor : tmp->neighbors)
                {
                    if (visited.count(neightbor) == 0)
                    {
                        visited.insert(neightbor);
                        q.push(neightbor);
                    }
                }
            }
        }
        
        return NULL;
    }
};