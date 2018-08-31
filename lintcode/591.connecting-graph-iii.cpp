class ConnectingGraph3 {
private:
    int size;
    vector<int> graph;
public:
    ConnectingGraph3(int n){
        size = n;
        graph.resize(n + 1);
        for (int i = 0; i < n + 1; ++i)
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

    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b)
        {
            graph[root_a] = root_b;
            size --;
        }
    }

    /**
     * @return: An integer
     */
    int query() {
        // write your code here
        return size;
    }
};