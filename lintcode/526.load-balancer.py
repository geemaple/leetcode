#  Tag: 
#  Time: O(1)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Implement a load balancer for web servers.
#  It provide the following functionality:
#  
#  1.
#  Add a new server to the cluster => `add(server_id)`.
#  2.
#  Remove a bad server from the cluster => `remove(server_id)`.
#  3.
#  Pick a server in the cluster randomly with equal probability => `pick()`.
#  
#  At beginning, the cluster is empty.
#  When `pick()` is called you need to randomly return a `server_id` in the cluster.
#  
#  **Example 1:**
#  ```
#  Input:
#    add(1)
#    add(2)
#    add(3)
#    pick()
#    pick()
#    pick()
#    pick()
#    remove(1)
#    pick()
#    pick()
#    pick()
#  Output:
#    1
#    2
#    1
#    3
#    2
#    3
#    3
#  Explanation: The return value of pick() is random, it can be either 2 3 3 1 3 2 2 or other.
#  ```
#  
#  

import random
class LoadBalancer:
    def __init__(self):
        # do intialization if necessary
        self.servers = []
        self.table = {}

    """
    @param: server_id: add a new server to the cluster
    @return: nothing
    """
    def add(self, server_id):
        # write your code here
        self.servers.append(server_id)
        self.table[server_id] = len(self.servers) - 1
        
    """
    @param: server_id: server_id remove a bad server from the cluster
    @return: nothing
    """
    def remove(self, server_id):
        # write your code here
        index = self.table[server_id]

        self.servers[index], self.servers[-1] = self.servers[-1], self.servers[index]
        del self.table[server_id]
        self.table[self.servers[index]] = index
        self.servers.pop()
        
    """
    @return: pick a server in the cluster randomly with equal probability
    """
    def pick(self):
        # write your code here
        return random.choice(self.servers)

