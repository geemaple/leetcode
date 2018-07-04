class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        unordered_set<int> nodes;
        for (auto seq: seqs){
            for (auto i = 0; i < seq.size(); ++i)
            {
                nodes.insert(seq[i]);
                
                if (i + 1 < seq.size())
                {
                    graph[seq[i]].push_back(seq[i + 1]);
                    indegree[seq[i + 1]] += 1;
                }
            }
        }
        
        vector<int> res;
        queue<int> starts;
        for (auto it = nodes.begin(); it != nodes.end(); ++it)
        {
            if (indegree.count(*it) == 0)
            {
                starts.push(*it);
            }
        }
        
        while (!starts.empty()) {
            
            if (starts.size() > 1)
            {
                return false;
            }
            
            int num = starts.front();
            starts.pop();
            res.push_back(num);
            
            vector<int> nodes = graph[num];
            for (auto i = 0; i < nodes.size(); ++i)
            {
                indegree[nodes[i]] -= 1;
                if (indegree[nodes[i]] == 0)
                {
                    starts.push(nodes[i]);
                    indegree.erase(nodes[i]);
                }
            }
        }
        
        return indegree.empty() ? (res == org) : false;
    }
};
