class UnionFind {
    vector<int> graph;
    int size;

public:
    UnionFind(int n)
    {
        graph.resize(n);
        size = n;
        for (int i = 0; i < n; ++i)
        {
            graph[i] = i;
        }
    }

    int find(int node)
    {
        if (graph[node] == node)
        {
            return node;
        }

        graph[node] = find(graph[node]);
        return graph[node];
    }

    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b){
            graph[root_a] = root_b;
            size--;
        }        
    }

    bool allConnnected()
    {
        return (size == 1);
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {

        if (n - 1 != edges.size()){
            return false;
        }

        UnionFind uf(n);
        for (auto p: edges)
        {
            uf.connect(p.first, p.second);
        }

        return uf.allConnnected();
    }
};


class Solution2 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // write your code here
        if (n != edges.size() + 1)
        {
            return false;
        }
        
        unordered_map<int, vector<int>> graph;
        for (auto i = 0; i < edges.size(); ++i)
        {
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        
        unordered_set<int> visted;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int tmp = q.front();
            q.pop();
            visted.insert(tmp);
            
            for (auto neighbor: graph[tmp])
            {
                if (visted.count(neighbor) == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        
        return visted.size() == n;
    }
};
