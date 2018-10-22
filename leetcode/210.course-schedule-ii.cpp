class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int>indegree;
        for (auto i = 0; i < prerequisites.size(); ++i)
        {
            indegree[prerequisites[i].first] ++;
            graph[prerequisites[i].second].push_back(prerequisites[i].first);
        }
        
        queue<int> q;
        for (auto i = 0; i < numCourses; ++i)
        {
            if (indegree.count(i) == 0)
            {
                q.push(i);
            }
        }
        
        vector<int> res;
        
        while (!q.empty())
        {
            int tmp = q.front();
            q.pop();
            
            res.push_back(tmp);
            
            for (auto neighbor : graph[tmp])
            {
                if (indegree.count(neighbor) > 0)
                {
                    indegree[neighbor] --;
                    if (indegree[neighbor] == 0)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return res.size() == numCourses ? res : vector<int>();
    }
};