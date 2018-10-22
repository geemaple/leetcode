class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        unordered_set<int> nodes;
        
        for (auto i = 0; i < seqs.size(); ++i)
        {
            vector<int> sequence = seqs[i];
            for (auto j = 0; j < sequence.size(); ++j)
            {
                nodes.insert(sequence[j]);
                if (j > 0)
                {
                    indegree[sequence[j]] += 1;
                    graph[sequence[j - 1]].push_back(sequence[j]);
                }
            }
        }
        
        queue<int> q;
        vector<int> res;
        for (auto n : nodes)
        {
            if (indegree.count(n) == 0)
            {
                q.push(n);
            }
        }
        
        while (!q.empty()) {
            
            if (q.size() > 1)
            {
                return false;
            }
            
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            vector<int> neighbors = graph[node];
            for (auto i = 0; i < neighbors.size(); ++i)
            {
                indegree[neighbors[i]] -= 1;
                if (indegree[neighbors[i]] == 0)
                {
                    indegree.erase(neighbors[i]);
                    q.push(neighbors[i]);
                }
            }
        }
        
        return indegree.empty() ? res == org: false;
    }
};
