//  Tag: 
//  Time: O(1)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Implement a load balancer for web servers.
//  It provide the following functionality:
//  
//  1.
//  Add a new server to the cluster => `add(server_id)`.
//  2.
//  Remove a bad server from the cluster => `remove(server_id)`.
//  3.
//  Pick a server in the cluster randomly with equal probability => `pick()`.
//  
//  At beginning, the cluster is empty.
//  When `pick()` is called you need to randomly return a `server_id` in the cluster.
//  
//  **Example 1:**
//  ```
//  Input:
//    add(1)
//    add(2)
//    add(3)
//    pick()
//    pick()
//    pick()
//    pick()
//    remove(1)
//    pick()
//    pick()
//    pick()
//  Output:
//    1
//    2
//    1
//    3
//    2
//    3
//    3
//  Explanation: The return value of pick() is random, it can be either 2 3 3 1 3 2 2 or other.
//  ```
//  
//  

class LoadBalancer {
public:
    unordered_map<int, int> table;
    vector<int> servers;
    LoadBalancer() {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here
        servers.push_back(server_id);
        table[server_id] = servers.size() - 1;
    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here
        int index = table[server_id];
        swap(servers[index], servers.back());
        
        table.erase(server_id);
        table[servers[index]] = index;

        servers.pop_back();
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        int index = rand() % servers.size();
        return servers[index];
    }
};