/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if (node == NULL)
        {
            return NULL;
        }
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mappings;
        unordered_set<UndirectedGraphNode *> visted;
        queue<UndirectedGraphNode *> q;
        q.push(node);
        visted.insert(node);
        
        while (!q.empty())
        {
            UndirectedGraphNode *cur = q.front();
            q.pop();
            
            if (mappings.count(cur) == 0)
            {
                mappings[cur] = new UndirectedGraphNode(cur->label);
            }
            
            for (auto i = 0; i < cur->neighbors.size(); ++i)
            {
                UndirectedGraphNode *neighbor = cur->neighbors[i];
                if (mappings.count(neighbor) == 0)
                {
                    mappings[neighbor] = new UndirectedGraphNode(neighbor->label);
                }
                
                mappings[cur]->neighbors.push_back(mappings[neighbor]);
                
                if (visted.count(neighbor) == 0)
                {
                    visted.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        return mappings[node];
    }
};