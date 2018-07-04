class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (auto courses : prerequisites) {
            indegree[courses.first] += 1;
            graph[courses.second].push_back(courses.first);
        }
        
        queue<int> starts;
        for (auto i = 0; i < numCourses; ++i)
        {
            if (indegree.count(i) == 0)
            {
                starts.push(i);
            }
        }
        
        while (!starts.empty()) {
            int course = starts.front();
            starts.pop();
            
            vector<int> nodes = graph[course];
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
        
        return indegree.empty();
    }
};
