class Solution(object):
    def ipToCIDR(self, ip, n):
        """
        :type ip: str
        :type n: int
        :rtype: List[str]
        """
        ips = ip.split('.')
        x = 0
        for i in range(len(ips)):
            x = x * 256 + int(ips[i])
            
        res = []
        while n > 0:
            step = x & -x
            while step > n:
                step /= 2
            ans = self.numberToIp(x, step)
            res.append(ans)
            x += step
            n -= step
        return res
    
    def numberToIp(self, x, step):
        ans = [0 for i in range(4)]
        ans[0] = (x >> 24) & 255
        ans[1] = (x >> 16) & 255
        ans[2] = (x >> 8) & 255
        ans[3] = (x >> 0) & 255

        length = 33
        while step > 0:
            length -= 1
            step /= 2

        return '.'.join([str(item) for item in ans]) + '/' + str(length)