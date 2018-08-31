class ConnectingGraph {
private:
    vector<int> graph;
public:
    /*
     * @param n: An integer
     */ConnectingGraph(int n) {
         // do intialization if necessary
         graph.resize(n + 1);
         for (int i = 1; i < n + 1; ++i)
         {
             graph[i] = i;
         }
     }
    
    int find(int node){
        
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
        int a_root = find(a);
        int b_root = find(b);
        
        graph[a_root] = b_root;
    }
    
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(a) == find(b);
    }
};