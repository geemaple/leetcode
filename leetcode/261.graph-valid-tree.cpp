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
