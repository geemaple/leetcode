/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */

class UnionFind {
    vector<int> graph;
    int size;
public:
    UnionFind(int n)
    {
        graph.resize(n);
        size = n;
        for(int i = 0; i < n; ++i)
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
    
    bool query(int a, int b)
    {
        return find(a) == find(b);
    }
    
    void connect(int a, int b)
    {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b)
        {
            graph[root_a] = root_b;
            size--;
        }
    }

    bool allConnected()
    {
        return size == 1;
    }
};

class Solution {
public:
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // Write your code here

        //sort according to cost
        auto comp = [](Connection& x, Connection& y){ 
            if (x.cost != y.cost){
                return x.cost < y.cost;
            }
            else if(x.city1 != y.city1)
            {
                return x.city1 < y.city1;
            }
            else
            {
                return x.city2 < y.city2;
            }
        };
        sort(connections.begin(), connections.end(), comp);
        
        // map city
        int count = 0;
        int size = connections.size();
        unordered_map<string, int> cityMap;
        for(int i = 0; i < size; ++i)
        {
            Connection conn = connections[i];
            
            if (cityMap.count(conn.city1) == 0)
            {
                cityMap[conn.city1] = count++;
            }

            if (cityMap.count(conn.city2) == 0)
            {
                cityMap[conn.city2] = count++;
            }
        }
        
        UnionFind uf(count);
    
        vector<Connection> res;
        
        for(int i = 0; i < size; ++i)
        {
            Connection conn = connections[i];
            int city1 = cityMap[conn.city1];
            int city2 = cityMap[conn.city2];
            
            if(!uf.query(city1, city2))
            {
                uf.connect(city1, city2);
                res.push_back(conn);
            }
        }
        
        return uf.allConnected() ? res: vector<Connection>();
    }
};