class LoadBalancer {
private:
    unordered_map<int, int> serverMapping;
    vector<int> list;
public:
    LoadBalancer() {
        // do intialization if necessary
    }
    
    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here

        if (serverMapping.count(server_id) > 0)
        {
            return;
        }

        list.push_back(server_id);
        serverMapping[server_id] = list.size() - 1;
    }
    
    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here

        if (serverMapping.count(server_id) == 0)
        {
            return;
        }

        int index = serverMapping[server_id];
        serverMapping.erase(server_id);
        
        // exchange with last
        list[index] = list[list.size() - 1];
        serverMapping[list[index]] = index;
        list.pop_back();
    }
    
    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        int random = rand() % list.size();
        return list[random];
    }
};