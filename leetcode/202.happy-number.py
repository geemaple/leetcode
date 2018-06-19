# O(N) n = steps to be a happy number
class Solution(object):
    def digitSquareSum(self, n):
        res = 0
        while(n):
            tmp = n % 10
            res += tmp * tmp
            n = n / 10
        return res

    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        res = n
        tries = set()

        while(res != 1):
            if res in tries:
                return False

            print res
            tries.add(res)
            res = self.digitSquareSum(res)

        return True
