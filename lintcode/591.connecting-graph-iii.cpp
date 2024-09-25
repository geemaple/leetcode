//  Tag: Union Find
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given `n` nodes in a graph, denoted `1` through `n`.
//  `ConnectingGraph3(n)` creates `n` nodes, and at the beginning there are no edges in the graph.
//  
//  You need to support the following method:
//  1.
//  `connect(a, b)`, an edge to connect node a and node b
//  2.
//  `query()`, Returns the number of connected component in the graph
//  
//  Example 1:
//  ```
//  Input:
//  ConnectingGraph3(5)
//  query()
//  connect(1, 2)
//  query()
//  connect(2, 4)
//  query()
//  connect(1, 4)
//  query()
//  
//  Output:[5,4,3,3]
//  
//  ```
//  
//  Example 2:
//  ```
//  Input:
//  ConnectingGraph3(6)
//  query()
//  query()
//  query()
//  query()
//  query()
//  
//  
//  Output:
//  [6,6,6,6,6]
//  
//  
//  ```
//  
//  A single node is also considered a connected component.

class ConnectingGraph3 {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
     vector<int> table;
     int count;
     ConnectingGraph3(int n): table(n + 1), count(n){
        // initialize your data structure here.
        for (int i = 0; i <= n; i++) {
            table[i] = i;
        }
    }
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            count--;
            table[root_a] = root_b;
        }
    }

    int find(int a) {
        if (a == table[a]) {
            return a;
        }
        table[a] = find(table[a]);
        return table[a];
    }

    /**
     * @return: An integer
     */
    int query() {
        // write your code here
        return count;
    }
};