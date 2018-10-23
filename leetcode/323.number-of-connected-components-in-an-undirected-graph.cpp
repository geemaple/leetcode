class Solution {
private:
    void bfs(unordered_map<int, vector<int>>& graph, int start, unordered_set<int>& visited)
    {        
        queue<int> q;
        q.push(start);
        visited.insert(start);
        
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            
            for (auto neighbor: graph[tmp])
            {
                if (visited.count(neighbor) == 0)
                {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        
        unordered_map<int, vector<int>>graph;
        unordered_set<int>visited;
        int count = 0;
        
        for (auto i = 0; i < edges.size(); ++i)
        {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        
        for (auto i = 0; i < n; ++i)
        {
            if (visited.count(i) == 0)
            {
                count++;
                bfs(graph, i, visited);
            }
        }
        
        return count;
    }
};