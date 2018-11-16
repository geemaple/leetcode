class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        res = [0 for i in range(len(T))]
        stack = []
        for j in range(len(T)):
            while stack and T[j] > T[stack[-1]]:
                i = stack.pop()
                res[i] = j - i
            stack.append(j)
            
        return res