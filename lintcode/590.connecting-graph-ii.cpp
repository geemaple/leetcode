class ConnectingGraph2 {
private:
    vector<int> graph;
    vector<int> size;

public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        graph.resize(n + 1);
        size.resize(n + 1);

        for (int i = 1; i < n + 1; ++i)
        {
            size[i] = 1;
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

    /*
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
            size[root_b] += size[root_a]; 
        }
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        int root_a = find(a);
        return size[root_a];
    }
};