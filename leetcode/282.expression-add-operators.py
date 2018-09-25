class Solution(object):

    def __init__(self, *args, **kwargs):
        self.num = None
        self.target = None

    def addOperators(self, num, target):
        """
        :type num: str
        :type target: int
        :rtype: List[str]
        """
        if num is None or len(num) == 0:
            return []

        self.num = num
        self.target = target

        res = []

        self.dfs(0, 0, 0, '', res)

        return res

    def dfs(self, pos, last, sum, path, res):
        if pos == len(self.num):
            if sum == self.target:
                res.append(path)
            return

        cur_val = 0
        cur = ''
        for i in range(pos, len(self.num)):
            
            cur_val = cur_val * 10 + int(self.num[i])
            cur += self.num[i]

            if pos == 0:
                self.dfs(i + 1, cur_val, cur_val, path + cur, res)
            else:
                self.dfs(i + 1, cur_val, sum + cur_val, path + '+' + cur, res)
                self.dfs(i + 1, -cur_val, sum - cur_val, path + '-' + cur, res)
                self.dfs(i + 1, last * cur_val, sum - last + last * cur_val, path + '*' + cur, res)

            if self.num[pos] == '0':
                break
