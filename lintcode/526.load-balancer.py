import random
class LoadBalancer:
    def __init__(self):
        # do intialization if necessary
        self.list = []
        self.mapping = {}
    """
    @param: server_id: add a new server to the cluster
    @return: nothing
    """
    def add(self, server_id):
        # write your code here

        if server_id in self.mapping:
            return

        self.list.append(server_id)
        self.mapping[server_id] = len(self.list) - 1

    """
    @param: server_id: server_id remove a bad server from the cluster
    @return: nothing
    """
    def remove(self, server_id):
        # write your code here

        if server_id not in self.mapping:
            return

        index = self.mapping[server_id]
        del self.mapping[server_id]

        self.list[index] = self.list[-1]
        self.mapping[self.list[index]] = index  
        self.list.pop()

    """
    @return: pick a server in the cluster randomly with equal probability
    """
    def pick(self):
        # write your code herer
        rand = random.randint(0, len(self.list) - 1)
        return self.list[rand]