class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        unordered_set<int> nodes;
        for (auto i = 0; i < seqs.size(); ++i)
        {
            vector<int> seq = seqs[i];
            for (auto j = 0; j < seq.size(); ++j)
            {
                nodes.insert(seq[j]);
                if (j + 1 < seq.size())
                {
                    graph[seq[j]].push_back(seq[j + 1]);
                    indegree[seq[j + 1]] += 1;
                }
            }
        }
        
        if (org.size() != nodes.size())
        {
            return false;
        }
        
        queue<int> q;
        for (auto it = nodes.begin(); it != nodes.end(); ++it)
        {
            if (indegree.count(*it) == 0)
            {
                q.push(*it);
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            if (q.size() > 1)
            {
                return false;
            }
            
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for (auto i = 0; i < graph[node].size(); ++i)
            {
                int neighbor = graph[node][i];
                if (indegree.count(neighbor) > 0)
                {
                    indegree[neighbor] -= 1;
                    if (indegree[neighbor] == 0)
                    {
                        indegree.erase(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return indegree.empty() ? org == res: false;
    }
};
