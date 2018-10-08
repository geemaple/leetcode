class ConnectingGraph {
private:
    vector<int> table;
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        for (auto i = 0; i <= n; ++i)
        {
            table.push_back(i);
        }
    }


    int find(int a){
        if (a == table[a])
        {
            return a;
        }
        
        table[a] = find(table[a]);
        return table[a];
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
            table[root_a] = root_b;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        return root_a == root_b;
    }
};