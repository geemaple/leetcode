class UnionFind {
private:
    vector<int> graph;
public:
    UnionFind(int n)
    {
        graph.resize(n);
    }

    void add(int node){
        graph[node] = node;
    }

    int find(int node){
        if (graph[node] == node)
        {
            return node;
        }

        graph[node] = find(graph[node]);
        return graph[node];
    }

    bool connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b)
        {
            graph[root_a] = root_b;
            return true;
        }

        return false;
    }

};

class Solution {
private:
    const int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    int convertPoint(int x, int y, int col)
    {
        return x * col + y;
    }

public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
       UnionFind uf = UnionFind(m * n);
       unordered_set<int> islands;
       vector<int> res;

       int size = 0;
       for (auto point: positions)
       {
            
            int x = point.first;
            int y = point.second;
            int x_y = convertPoint(x, y, n);

            if (islands.count(x_y) == 0)
            {
                islands.insert(x_y);
                uf.add(x_y);
                size++;

                for (int i = 0; i < 4; ++i)
                {
                    int new_x = directions[i][0] + x;
                    int new_y = directions[i][1] + y;
                    if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n)
                    {
                        int new_x_y = convertPoint(new_x, new_y, n);
                        if (islands.count(new_x_y) > 0)
                        {
                            if (uf.connect(x_y, new_x_y))
                            {
                                size--;
                            }
                        }
                    }
                }
            }

            res.push_back(size);
       }

       return res;
    }
};
