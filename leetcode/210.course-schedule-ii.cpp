class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;
        for (auto course: prerequisites)
        {
            graph[course.second].push_back(course.first);
            indegree[course.first] += 1;
        }
        
        queue<int> starts;
        vector<int> res;
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
            res.push_back(course);
            
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
        
        return indegree.empty() ? res : vector<int>();
    }
};
